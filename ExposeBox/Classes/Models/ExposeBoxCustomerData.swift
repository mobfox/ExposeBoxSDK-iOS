//
//  ExposeBoxCustomerData.swift
//  ExposeBoxSDK
//
//  Created by Viktor Shchepanovskyi on 13.01.2020.
//  Copyright © 2020 Market.com. All rights reserved.
//

import UIKit

/// Data container for Customer data
@objc public class ExposeBoxCustomerData: NSObject {
    /// Customer First name
    public var firstName: String?
    /// Customer Last name
    public var lastName: String?
    /// Customer email
    public var email: String
    /// Cutomer identifier
    public var customerId: String?
    /// Additionalm information about customer
    public var additionalInfo: [String: String]?

    /**
     Data container for Customer data
     - Parameter email: Customer email
     */
    @objc public init(email: String) {
        self.email = email
        super.init()
    }

    func dictionaryRepresentation() -> [String: String] {
        var result: [String: String] = ["email": email]
        if let customerId = customerId {
            result["customerId"] = customerId
        }
        if let firstName = firstName {
            result["firstName"] = firstName
        }
        if let lastName = lastName {
            result["lastName"] = lastName
        }
        if let additionalInfo = additionalInfo {
            for (key, value) in additionalInfo {
                result[key] = value
            }
        }
        return result
    }

}
