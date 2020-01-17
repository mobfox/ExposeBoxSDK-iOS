//
//  ExposeBoxErrors.swift
//  ExposeBoxSDK
//
//  Created by Viktor Shchepanovskyi on 10.01.2020.
//  Copyright © 2020 Market.com. All rights reserved.
//

import Foundation

/// ExposeBox SDK Error domain
public let kExposeBoxErrorDomain = "ExposeBoxError"
/// Error produced by incorrect data format
public let kExposeBoxErrorCodeParse = 1
/// Error produced by incorrect URL arguments
public let kExposeBoxErrorCodeURLIssues = 0

extension NSError {

    static func parsingError(_ additionalDescription: String = "") -> NSError {
        return NSError(domain: kExposeBoxErrorDomain,
                       code: kExposeBoxErrorCodeParse,
                       userInfo: [NSLocalizedDescriptionKey: additionalDescription])
    }

    static func urlError(_ additionalDescription: String = "") -> NSError {
        return NSError(domain: kExposeBoxErrorDomain,
                       code: kExposeBoxErrorCodeURLIssues,
                       userInfo: [NSLocalizedDescriptionKey: additionalDescription])
    }

}
