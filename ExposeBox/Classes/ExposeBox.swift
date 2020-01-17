//
//  ExposeBox.swift
//  ExposeBoxSDK
//
//  Created by Viktor Shchepanovskyi on 16.12.2019.
//  Copyright © 2019 Market.com. All rights reserved.
//

import UIKit
import AdSupport

@objc protocol ExposeBoxProtocol: NSObjectProtocol {
    func view(name: String)
    func setProducts(_ products: [String])
    func setCategories(_ categories: [String])
    func setTags(_ tags: [String: [String]])
    func setCustomerData(_ data: ExposeBoxCustomerData)

    func addToCart(productId: String, quantity: Int, unitPrice: Float)
    func removeFromCart(productId: String, quantity: Int)

    func conversion(orderId: String, totalPrice: Float, cartProducts: [ExposeBoxCartProduct])
    func event(name: String, data: [String: AnyHashable])
    func click(placementId: String, widgetId: Int, productId: String, additionalData: Any?)
    func realImpression(_ batches: [ExposeBoxRealImpressionBatch])
    func recommendations(placementIds: [String], completion: @escaping RequestHandler)

    func addToWishlist(productId: String)
    func removeFromWishlist(productId: String)
    func apporove(coupon: String)
    func request(coupon: String)
}

/// ExposeBox SDK class, use *shared*, **companyId** is required to send data
public class ExposeBox: NSObject {
    private var sender: Networking?
    private let storage = MemoryStorage()
    private let startTimestamp = Date().timeIntervalSince1970
    private let reachability = try? Reachability()
    private var shouldRetry = false

    /// ExposeBox SDK class **shared instance**, **companyId** is required to send data
    @objc public static let shared = ExposeBox()
    /// ExposeBox company identifier, **companyId** is required to send data
    @objc public var companyId: String? {
        didSet {
            if let companyId = companyId {
                let configuration = Configuration(companyId: companyId)
                sender = Networking(configuration: configuration)
                sender?.delegate = self
                triggerSending()

                reachability?.whenReachable = { [weak self] _ in
                    self?.shouldRetry = true
                    self?.triggerSending()
                }
            }
        }
    }
    /// ExposeBox company identifier of *application* in scope. As example *iOS* or *Android*, etc.
    @objc public var appId: String?
    private var advertiserId: String? {
        if ASIdentifierManager.shared().isAdvertisingTrackingEnabled {
            return ASIdentifierManager.shared().advertisingIdentifier.uuidString
        } else {
            return nil
        }
    }

    /// Set *true* if you want to see more information about data sent in system logs.
    ///  **Don't use in release versions.**
    @objc public var versboseLogging: Bool = false {
        didSet {
            sender?.versboseLogging = versboseLogging
        }
    }

    private func triggerSending() {
        guard let sender = sender, !sender.uploading, let next = storage.getItem() else {
            return
        }
        sender.send(next)
    }

}

extension ExposeBox: NetworkingDelegate {
    func sent(_ element: Request, success: Bool) {
        if success {
            // remove element
            // put next
            storage.remove(element)
            triggerSending()
        } else {
            // wait for reachability change
            // dont remove first in queue
            if shouldRetry {
                shouldRetry = false
                triggerSending()
            }
        }
    }
}

extension ExposeBox: ExposeBoxProtocol {
    /**
        View event, send when item (or screen) is viewed,
     alternatively can be used as *reportExposeBoxView(name: String)* in *UIViewController*
        - Parameter name: name of item or screen
     */
    public func view(name: String) {
        let request = Request(type: .view,
                              method: .get,
                              sessionStartTimestamp: startTimestamp,
                              appId: appId,
                              advertiserId: advertiserId)
        request.set(payload: ["viewName": name])
        storage.append(request)
        triggerSending()
    }

    /**
       View event, send **products** which were viewed
       - Parameter products: array of Product identifiers
    */
    public func setProducts(_ products: [String]) {
        let request = Request(type: .view,
                              method: .get,
                              sessionStartTimestamp: startTimestamp,
                              appId: appId,
                              advertiserId: advertiserId)
        request.set(payload: ["products": products])
        storage.append(request)
        triggerSending()
    }

    /**
       View event, send **categories**
       - Parameter categories: array of Category identifiers
    */
    public func setCategories(_ categories: [String]) {
        let request = Request(type: .view,
                              method: .get,
                              sessionStartTimestamp: startTimestamp,
                              appId: appId,
                              advertiserId: advertiserId)
        request.set(payload: ["categories": categories])
        storage.append(request)
        triggerSending()
    }

    /**
       View event, send Tags
       - Parameter tags: dictionary with String *keys* and Array of String as *values*
    */
    public func setTags(_ tags: [String: [String]]) {
        let request = Request(type: .view,
                              method: .get,
                              sessionStartTimestamp: startTimestamp,
                              appId: appId,
                              advertiserId: advertiserId)
        request.set(payload: ["tags": tags])
        storage.append(request)
        triggerSending()
    }

    /**
       Add products to cart
       - Parameter productId: identifier of Product
       - Parameter quantity: number of items
       - Parameter unitPrice: price per item
    */
    public func addToCart(productId: String, quantity: Int = 1, unitPrice: Float = 0) {
        let request = Request(type: .event,
                              method: .get,
                              sessionStartTimestamp: startTimestamp,
                              appId: appId,
                              advertiserId: advertiserId)
        request.set(payload: ["addToCart": ["productId": productId, "quantity": quantity, "unitPrice": unitPrice]])
        storage.append(request)
        triggerSending()
    }

    /**
       Remove products from cart
       - Parameter productId: identifier of Product
       - Parameter quantity: number of items
    */
    public func removeFromCart(productId: String, quantity: Int = 1) {
        let request = Request(type: .event,
                              method: .get,
                              sessionStartTimestamp: startTimestamp,
                              appId: appId,
                              advertiserId: advertiserId)
        request.set(payload: ["removeFromCart": ["productId": productId, "quantity": quantity]])
        storage.append(request)
        triggerSending()
    }

    /**
       Send customer data information
       - Parameter data: ExposeBoxCustomerData with customer data fields
    */
    public func setCustomerData(_ data: ExposeBoxCustomerData) {
        let request = Request(type: .view,
                              method: .get,
                              sessionStartTimestamp: startTimestamp,
                              appId: appId,
                              advertiserId: advertiserId)
        request.set(payload: ["customer": data.dictionaryRepresentation()])
        storage.append(request)
        triggerSending()
    }

    /**
       Order complete / placed, conversion event
       - Parameter orderId: identifier of Order
       - Parameter totalPrice: Total price of Items
       - Parameter cartProducts: Array of Products purchased
    */
    public func conversion(orderId: String, totalPrice: Float, cartProducts: [ExposeBoxCartProduct]) {
        let request = Request(type: .event,
                              method: .get,
                              sessionStartTimestamp: startTimestamp,
                              appId: appId,
                              advertiserId: advertiserId)
        guard let batchesConvertedData = try? JSONEncoder().encode(cartProducts),
            let string = String(data: batchesConvertedData, encoding: .utf8) else {
            return
        }
        request.set(payload: ["order": ["orderId": orderId, "totalPrice": totalPrice, "cartProducts": string]])
        storage.append(request)
        triggerSending()
    }

    /**
       Custom event
       - Parameter name: name of event
       - Parameter data: dictionary with event information
    */
    public func event(name: String, data: [String: AnyHashable]) {
        let request = Request(type: .event,
                              method: .get,
                              sessionStartTimestamp: startTimestamp,
                              appId: appId,
                              advertiserId: advertiserId)
        request.set(payload: ["event": name, "data": data])
        storage.append(request)
        triggerSending()
    }

    /**
       Click event
       - Parameter placementId: identifier of Placement
       - Parameter widgetId: identifier of Widget
       - Parameter productId: identifier of Product
       - Parameter additionalData: additional information
    */
    public func click(placementId: String, widgetId: Int, productId: String, additionalData: Any?) {
        let additionalData = additionalData as? Encodable ?? ""
        let request = Request(type: .event,
                              method: .get,
                              sessionStartTimestamp: startTimestamp,
                              appId: appId,
                              advertiserId: advertiserId)
        request.set(payload: ["click": ["placementId": placementId,
                                        "widgetId": widgetId,
                                        "productId": productId,
                                        "additionalData": additionalData]])
        storage.append(request)
        triggerSending()
    }

    /**
       Send array of impression events, look at **RealImpressionBatch** to fill contents
       - Parameter batches: array of **RealImpressionBatch**
    */
    public func realImpression(_ batches: [ExposeBoxRealImpressionBatch]) {
        let request = Request(type: .event,
                              method: .get,
                              sessionStartTimestamp: startTimestamp,
                              appId: appId,
                              advertiserId: advertiserId)
        guard let batchesConvertedData = try? JSONEncoder().encode(batches),
            let string = String(data: batchesConvertedData, encoding: .utf8) else {
            return
        }
        request.set(payload: ["realImpression": string])
        storage.append(request)
        triggerSending()
    }

    /**
       Request recommendations for user
       - Parameter placementIds: array of placement identifiers
       - Parameter completion: handler for received response data
    */
    public func recommendations(placementIds: [String], completion: @escaping RequestHandler) {
        let request = Request(type: .recommendations,
                              method: .post,
                              sessionStartTimestamp: startTimestamp,
                              appId: appId,
                              advertiserId: advertiserId)
        request.body = ["companyId": companyId, "placementIds": placementIds]
        sender?.requestRecommendations(request, completion: completion)
    }

    /**
       Add product to *Wishlist*
       - Parameter productId: identifier of Product
    */
    public func addToWishlist(productId: String) {
        let request = Request(type: .event,
                              method: .get,
                              sessionStartTimestamp: startTimestamp,
                              appId: appId,
                              advertiserId: advertiserId)
        request.set(payload: ["addToWishlist": ["productId": productId]])
        storage.append(request)
        triggerSending()
    }

    /**
       Remove product from *Wishlist*
       - Parameter productId: identifier of Product
    */
    public func removeFromWishlist(productId: String) {
        let request = Request(type: .event,
                              method: .get,
                              sessionStartTimestamp: startTimestamp,
                              appId: appId,
                              advertiserId: advertiserId)
        request.set(payload: ["removeFromWishlist": ["productId": productId]])
        storage.append(request)
        triggerSending()
    }

    /**
       Approve *Coupon*
       - Parameter coupon: identifier of Coupon
    */
    public func apporove(coupon: String) {
        let request = Request(type: .event,
                              method: .get,
                              sessionStartTimestamp: startTimestamp,
                              appId: appId,
                              advertiserId: advertiserId)
        request.set(payload: ["approveCoupon": ["couponId": coupon]])
        storage.append(request)
        triggerSending()
    }

    /**
       Request *Coupon*
       - Parameter coupon: identifier of Coupon
    */
    public func request(coupon: String) {
        let request = Request(type: .event,
                              method: .get,
                              sessionStartTimestamp: startTimestamp,
                              appId: appId,
                              advertiserId: advertiserId)
        request.set(payload: ["requestCoupon": ["couponId": coupon]])
        storage.append(request)
        triggerSending()
    }

    // TODO: Future, not implemented on BE - hasGdprConsent, setCoppaCompliance
}
