//
//  MemoryStorage.swift
//  ExposeBoxSDK
//
//  Created by Viktor Shchepanovskyi on 16.12.2019.
//  Copyright © 2019 Market.com. All rights reserved.
//

import UIKit

class MemoryStorage: NSObject {
    var array: [Request] = []
}

extension MemoryStorage: Storage {

    func append(_ item: Request) {
        array.append(item)
    }

    func append(_ items: [Request]) {
        array.append(contentsOf: items)
    }

    func getItem() -> Request? {
        return array.first
    }

    func getItems(count: UInt) -> [Request]? {
        var result: [Request] = []
        for index in 0...( min( Int(count), array.count) - 1) {
            result.append(array[index])
        }
        return result
    }

    func remove(_ item: Request) {
        if let position = array.firstIndex(of: item) {
            array.remove(at: position)
        }
    }

    func remove(_ items: [Request]) {
        items.forEach {
            remove($0)
        }
    }

    var count: Int {
        return array.count
    }
}
