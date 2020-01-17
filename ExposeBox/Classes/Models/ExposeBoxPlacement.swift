//
//  Placement.swift
//  ExposeBoxSDK
//
//  Created by Viktor Shchepanovskyi on 23.12.2019.
//  Copyright © 2019 Market.com. All rights reserved.
//

import Foundation

/// Object for placement with products, recommendations response
public class ExposeBoxPlacement: NSObject {
    /// Placement identifier
    public var placement: String

    /// List of products for placement
    public var products: [String: AnyHashable]?

    /**
     Object for placement with products, recommendations response
     - Parameter placement: Placement identifier
     - Parameter products: List of products for placement
     */
    init(placement: String, products: [String: AnyHashable]?) {
        self.placement = placement
        self.products = products
        super.init()
    }
}
