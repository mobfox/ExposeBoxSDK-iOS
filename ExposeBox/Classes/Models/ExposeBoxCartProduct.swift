//
//  CartProduct.swift
//  ExposeBoxSDK
//
//  Created by Viktor Shchepanovskyi on 17.12.2019.
//  Copyright © 2019 Market.com. All rights reserved.
//

import UIKit

/// Object for cart product representation
@objc public class ExposeBoxCartProduct: NSObject, Encodable {
    /// Identifier of product
    public var productId: String
    /// Quantity of products
    public var quantity: Int
    /// Price per Unit
    public var unitPrice: Float
    /**
     Object for cart product representation
     - Parameter productId: Identifier of product
     - Parameter quantity: Quantity of products
     - Parameter unitPrice: Price per Unit
     */

    @objc public init(productId: String, quantity: Int, unitPrice: Float) {
        self.productId = productId
        self.quantity = quantity
        self.unitPrice = unitPrice
        super.init()
    }

    enum MyStructKeys: String, CodingKey {
      case productId
      case quantity
      case unitPrice
    }

    /// Encodable to JSON
    public func encode(to encoder: Encoder) throws {
        var container = encoder.container(keyedBy: MyStructKeys.self)
        try container.encode(productId, forKey: .productId)
        try container.encode(quantity, forKey: .quantity)
        try container.encode(unitPrice, forKey: .unitPrice)
    }
}
