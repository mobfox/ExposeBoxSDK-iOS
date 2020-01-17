//
//  Decode.swift
//  ExposeBoxSDK
//
//  Created by Viktor Shchepanovskyi on 10.01.2020.
//  Copyright © 2020 Market.com. All rights reserved.
//

import Foundation

enum Decode {

    static func decodeRecommendations(from response: NSDictionary) -> [ExposeBoxPlacement]? {
        var result: [ExposeBoxPlacement] = []
        if let placementsDictionary = response.object(forKey: "placements") as? [String: [String: AnyHashable]] {
            for (key, value) in placementsDictionary {
                let placement = ExposeBoxPlacement(placement: key, products: value)
                result.append(placement)
            }
        }
        return result
    }

}
