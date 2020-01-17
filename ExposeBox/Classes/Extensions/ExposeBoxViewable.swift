//
//  ExposeBoxViewable.swift
//  ExposeBoxSDK
//
//  Created by Viktor Shchepanovskyi on 23.12.2019.
//  Copyright © 2019 Market.com. All rights reserved.
//

import UIKit

/**
    Extension for sending view event for view with name, *alternative* of *ExposeBox.shared view(name:)*
*/
public extension UIViewController {
    /**
        Send view event for view with name

        - Parameter name: name of view / screen / item.
    */
    @objc func reportExposeBoxView(name: String) {
        ExposeBox.shared.view(name: name)
    }
}
