//
//  Networking.swift
//  ExposeBoxSDK
//
//  Created by Viktor Shchepanovskyi on 16.12.2019.
//  Copyright © 2019 Market.com. All rights reserved.
//

import UIKit

protocol NetworkingDelegate: class {
    func sent(_ element: Request, success: Bool)
}

/**
    Basic request handler, suitable for Swift and Objective-C usage

    - Returns: *Object* - result object if request or operation success.
                *Error* - error if failed, nil if success.
*/
public typealias RequestHandler = (Any?, Error?) -> Void

class Networking: NSObject {
    let configuration: Configuration
    weak var delegate: NetworkingDelegate?
    var versboseLogging: Bool = false
    var uploading: Bool = false

    init(configuration: Configuration) {
        self.configuration = configuration
        super.init()
    }

    func send(_ request: Request) {
        uploading = true
        send(request) { [weak self] _, error in
            self?.uploading = false
            if error == nil {
                self?.delegate?.sent(request, success: true)
            } else {
                self?.delegate?.sent(request, success: false)
            }
        }
    }

    func requestRecommendations(_ element: Request, completion: @escaping RequestHandler) {
        send(element) { result, error in
            if error != nil {
                completion(nil, error)
            } else {
                if let result = result as? NSDictionary {
                    let parsed = Decode.decodeRecommendations(from: result)
                    completion(parsed, nil)
                } else {
                    completion(nil, NSError.parsingError())
                }
            }
        }
    }
}

private extension Networking {

    func send(_ request: Request, completion: @escaping RequestHandler) {
        guard let url = URL(string: configuration.url(for: request.type, query: request.query)) else {
            completion(nil, NSError.urlError())
            return
        }

        let writeLogs = versboseLogging
        var urlRequest = URLRequest(url: url)
        urlRequest.httpMethod = request.method.rawValue
        if let body = request.body {
            let str = Encode.query(body)
            let data = str.data(using: .utf8)
            urlRequest.httpBody = data
        }

        if writeLogs {
            print("Request url: \(url)")
        }

        let task = URLSession.shared.dataTask(with: urlRequest) { data, response, error in
            if writeLogs {
                print("Response: \(String(describing: response))")
                print("Error: \(String(describing: error))")
            }
            if let error = error {
                completion(nil, error)
            } else {
                if let data = data, data.count > 0 {
                    if let objects = try? JSONSerialization.jsonObject(with: data, options: .allowFragments) {
                        completion(objects, nil)
                        if writeLogs {
                            print("Objects: \(String(describing: objects))")
                        }
                    } else {
                        completion(nil, NSError.parsingError())
                    }
                } else {
                    completion(nil, nil)
                }
            }
        }
        task.resume()
    }

}
