//
//  Request.swift
//  ExposeBoxSDK
//
//  Created by Viktor Shchepanovskyi on 16.12.2019.
//  Copyright © 2019 Market.com. All rights reserved.
//

import UIKit

enum HTTPMethod: String {
    case post = "POST"
    case get = "GET"
}

enum RequestType: String {
    case view = "view"
    case event = "event"
    case recommendations = "item-recommendations"
}

class Request: NSObject {
    let method: HTTPMethod
    let type: RequestType
    private let timestamp: TimeInterval
    private let sessionDuration: TimeInterval
    private let appId: String?
    private let advertiserId: String?
    var query: String = ""
    var body: [String: AnyHashable]?

    init(type: RequestType,
         method: HTTPMethod,
         sessionStartTimestamp: TimeInterval,
         appId: String? = "",
         advertiserId: String? = "") {
        self.type = type
        self.method = method
        self.timestamp = Date().timeIntervalSince1970
        self.sessionDuration = timestamp - sessionStartTimestamp
        self.appId = appId
        self.advertiserId = advertiserId
        super.init()
        self.query = query(from: nil)
    }

    func set(payload: [String: Any]) {
        self.query = query(from: payload)
    }

    private func query(from payload: [String: Any]?) -> String {
        guard method == .get else {
            return ""
        }

        var components = URLComponents()
        var queryItems = [URLQueryItem(name: "appId", value: appId),
                                 URLQueryItem(name: "advertiserId", value: advertiserId),
                                 URLQueryItem(name: "timestamp", value: "\(Int64(timestamp))"),
                                 URLQueryItem(name: "sessionDuration", value: "\(Int64(sessionDuration))")
        ]
        if let payload = payload {
            queryItems.append(contentsOf: payload.compactMap { (arg) -> URLQueryItem? in
                let (key, value) = arg
                if let string = value as? String {
                    return URLQueryItem(name: key, value: string)
                } else if let value = value as? Int {
                    return URLQueryItem(name: key, value: "\(value)")
                } else if let value = value as? Float {
                    return URLQueryItem(name: key, value: "\(value)")
                } else if let jsonData = try? JSONSerialization.data(withJSONObject: value),
                    let string = String(data: jsonData, encoding: .utf8) {
                    return URLQueryItem(name: key, value: string)
                } else {
                    return nil
                }
            })
        }
        components.queryItems = queryItems
        let string = components.url?.absoluteString ?? ""
        let chars = CharacterSet.urlFragmentAllowed
        return string.addingPercentEncoding(withAllowedCharacters: chars) ?? ""
    }
}
