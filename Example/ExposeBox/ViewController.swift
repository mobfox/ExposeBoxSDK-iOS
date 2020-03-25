//
//  ViewController.swift
//  ExposeBox
//
//  Created by Viktor Shchepanovskyi on 01/17/2020.
//  Copyright (c) 2020 Viktor Shchepanovskyi. All rights reserved.
//

import UIKit
import ExposeBoxSDK

class ViewController: UIViewController {

    @IBOutlet weak var tableView: UITableView!

    let reuseId = "reuseId"

    struct ActionBinding {
        typealias SomeAction = () -> Void
        let name: String
        let action: SomeAction
    }

    var actions: [ActionBinding] = [
        ActionBinding(name: "Send View",
                      action: {
                        ExposeBox.shared.view(name: "MainView") // first type view reporting
        }),
        ActionBinding(name: "Send Categories",
                      action: {
                         ExposeBox.shared.setCategories(["String1", "String2"])
        }),
        ActionBinding(name: "Send Products",
                      action: {
                         ExposeBox.shared.setProducts(["1111", "2222"])
        }),
        ActionBinding(name: "Send Tags",
                      action: {
                         ExposeBox.shared.setTags(["String" : ["String", "tags"]])
        }),
        ActionBinding(name: "Add to Cart",
                      action: {
                         ExposeBox.shared.addToCart(productId: "2222", quantity: 23, unitPrice: 22.2)
        }),
        ActionBinding(name: "Remove from Cart",
                      action: {
                         ExposeBox.shared.removeFromCart(productId: "2222", quantity: 20)
        }),
        ActionBinding(name: "Send Customer Data",
                      action: {
                        let customerData = ExposeBoxCustomerData(email: "iostest@exposebox.com")
                        customerData.firstName = "John"
                        customerData.lastName = "Sunny"
                        customerData.customerId = "65743987"
                        customerData.additionalInfo = ["CUSTOM": "DATA"]
                        ExposeBox.shared.setCustomerData(customerData)
        }),
        ActionBinding(name: "Send Order / Conversion",
                      action: {
                         ExposeBox.shared.conversion(orderId: "234", totalPrice: 22.2, cartProducts: [ExposeBoxCartProduct(productId: "2222", quantity: 1, unitPrice: 1)])
        }),
        ActionBinding(name: "Send Event",
                      action: {
                         ExposeBox.shared.event(name: "event", data: ["custom" : "data"])
        }),
        ActionBinding(name: "Send Click",
                      action: {
                         ExposeBox.shared.click(placementId: "dashboard", widgetId: 1, productId: "123", additionalData: ["some": "data"])
        }),
        ActionBinding(name: "Real Impression",
                      action: {
                         ExposeBox.shared.realImpression([ExposeBoxRealImpressionBatch(placementId: "dashboard", widgetId: 1, items: [["String" : "String"]] )])
        }),
        ActionBinding(name: "Add to Wishlist",
                      action: {
                         ExposeBox.shared.addToWishlist(productId: "some")
        }),
        ActionBinding(name: "Remove from Wishlist",
                      action: {
                        ExposeBox.shared.removeFromWishlist(productId: "some")
        }),
        ActionBinding(name: "Approve Coupon",
                      action: {
                         ExposeBox.shared.apporove(coupon: "MAX")
        }),
        ActionBinding(name: "Request Coupon",
                      action: {
                         ExposeBox.shared.request(coupon: "MAX")
        }),
        ActionBinding(name: "Test Recommendations",
                      action: {
                         ExposeBox.shared.recommendations(placementIds: ["3332", "2345"]) { objects, error in
                             print("Objects: \(String(describing: objects))")
                             print("Error: \(String(describing: error))")
                         }
        })
    ]

    override func viewDidLoad() {
        super.viewDidLoad()
        tableView.register(UITableViewCell.self, forCellReuseIdentifier: reuseId)

        setup()

        // second type view reporting
        reportExposeBoxView(name: "Main")
    }

    func setup() {
        let expose = ExposeBox.shared
        expose.companyId = "30510" // init with your company id
        expose.versboseLogging = true
    }

}

extension ViewController: UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return actions.count
    }

    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        var cell = tableView.dequeueReusableCell(withIdentifier: reuseId)
        if cell == nil {
            cell = UITableViewCell(style: .default, reuseIdentifier: reuseId)
        }
        let name = actions[indexPath.row].name
        cell?.textLabel?.text = name
        return cell!
    }
}

extension ViewController: UITableViewDelegate {
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        let action = actions[indexPath.row].action
        action()
        showSuccess()
    }
}

private extension ViewController {

    func showAlert(with text: String) {
        let alertController = UIAlertController(title: "Example", message: text, preferredStyle: .alert)
        alertController.addAction(UIAlertAction(title: "OK", style: .cancel, handler: nil))
        show(alertController, sender: nil)
    }

    func showSuccess() {
        showAlert(with: "Action Sent")
    }

}
