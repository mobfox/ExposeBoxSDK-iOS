//
//  Storage.swift
//  ExposeBoxSDK
//
//  Created by Viktor Shchepanovskyi on 16.12.2019.
//  Copyright © 2019 Market.com. All rights reserved.
//

import UIKit

protocol Storage: NSObject {
    func append(_ item: Request)
    func append(_ items: [Request])

    func getItem() -> Request?
    func getItems(count: UInt) -> [Request]?

    func remove(_ item: Request)
    func remove(_ items: [Request])

    var count: Int { get }
}
