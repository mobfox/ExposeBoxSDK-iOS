//
//  Configuration.swift
//  ExposeBoxSDK
//
//  Created by Viktor Shchepanovskyi on 16.12.2019.
//  Copyright © 2019 Market.com. All rights reserved.
//

import UIKit

class Configuration: NSObject {
    let companyId: String
    var baseURLString: String {
        return "https://server.exposebox.com/px/\(companyId)/"
    }
    var recommendationsURLString: String {
        return "https://server.exposebox.com/api/"
    }

    func url(for requestType: RequestType, query: String) -> String {
        if requestType == .recommendations {
            return recommendationsURLString + requestType.rawValue + query
        } else {
            return baseURLString + requestType.rawValue + query
        }
    }

    init(companyId: String) {
        self.companyId = companyId
        super.init()
    }
}
