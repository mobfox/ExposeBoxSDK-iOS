//
//  RealImpressionBatch.swift
//  ExposeBoxSDK
//
//  Created by Viktor Shchepanovskyi on 16.12.2019.
//  Copyright © 2019 Market.com. All rights reserved.
//

import UIKit

/// Batch object to group real impression objects
@objc public class ExposeBoxRealImpressionBatch: NSObject {
    /// Identifier of placement
    public var placementId: String
    /// Identifier of widget
    public var widgetId: Int
    /// Items key value pairs
    public var items: [String: String]

    /**
        Batch object to group real impression objects
        - Parameter placementId: Identifier of placement
        - Parameter widgetId: Identifier of widget
        - Parameter items: Items key value pairs
    */
    @objc public init(placementId: String, widgetId: Int, items: [String: String]) {
        self.placementId = placementId
        self.widgetId = widgetId
        self.items = items
        super.init()
    }

    enum MyStructKeys: String, CodingKey {
      case placementId
      case widgetId
      case items
    }
}

extension ExposeBoxRealImpressionBatch: Encodable {
    /// Encodable to JSON
    public func encode(to encoder: Encoder) throws {
        var container = encoder.container(keyedBy: MyStructKeys.self)
        try container.encode(placementId, forKey: .placementId)
        try container.encode(widgetId, forKey: .widgetId)
        try container.encode(items, forKey: .items)
    }
}
