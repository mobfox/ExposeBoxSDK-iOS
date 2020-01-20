# ExposeBox

[![Version](https://img.shields.io/cocoapods/v/ExposeBox.svg?style=flat)](https://cocoapods.org/pods/ExposeBox)
[![License](https://img.shields.io/cocoapods/l/ExposeBox.svg?style=flat)](https://cocoapods.org/pods/ExposeBox)
[![Platform](https://img.shields.io/cocoapods/p/ExposeBox.svg?style=flat)](https://cocoapods.org/pods/ExposeBox)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Installation

ExposeBox is available through [CocoaPods](https://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'ExposeBox'
```

## Usage

Import the framework (required) 
```swift
import ExposeBoxSDK 
```
Set your *companyId* (required). All data sent before setting companyId will be ignored. 
```swift
ExposeBox.shared.companyId = "COMPANY_ID" 
```
Set your *appId* (optional) 
```swift
ExposeBox.shared.appId = "APP_ID" 
```
*companyId* is your company's ID, *appId* is your app's ID, both provided by ExposeBox.

Then you can use ExposeBox across your app. 

## Methods

### Track a page view
```swift
ExposeBox.shared.view(name: "MainView") 
```
or alternatively from instance of *UIViewController*: 
```swift
reportExposeBoxView(name: "MainView") 
```
### Set Categories
```swift
ExposeBox.shared.setCategories(["Category1", "Category2"]) 
```
### Set Products
```swift
ExposeBox.shared.setProducts(["e349vb", "x980tmw"])
```
In case of a single product, you can provide an array with a single element

### Set Tags
```swift
ExposeBox.shared.setTags(["Key" : ["Key", "Value"]])
```

### Add and Remove from Cart
Use this when your customer is adding or removing items from the cart, where *productId*  is your product's SKU, quantity  is the quantity of the same product added, and price  the product's unit price
```swift
ExposeBox.shared.addToCart(productId: "ID", quantity: INT, unitPrice: FLOAT)

ExposeBox.shared.removeFromCart(productId: "ID", quantity: INT)
```
### Add and Remove from Wishlist
```swift
ExposeBox.shared.addToWishlist(productId: "ID")

ExposeBox.shared.removeFromWishlist(productId: "ID")
```
### Approve and Request a Coupon
```swift
ExposeBox.shared.apporove(coupon: "COUPON")

ExposeBox.shared.request(coupon: "COUPON")
```
### Customer Data
Setting customer details enables ExposeBox send automated emails and synchronise offline data with online data.

Use this when the customer is logged in and the data is available.

First, create the *CustomerData* object
```swift
let customerData = ExposeBoxCustomerData(email: "EMAIL")
customerData.firstName = "FIRST"
customerData.lastName = "LAST"
customerData.customerId = "ID"
customerData.additionalInfo = ["CUSTOM": "DATA"]
ExposeBox.shared.setCustomerData(customerData)
```
Other fields like city, zip code, address, phone, etc are available via additional info.

Then send it through ExposeBox

### Custom Event
You can send custom events with data
```swift
ExposeBox.shared.event(name: "EVENT", data: ["CUSTOM" : "DATA"])
```
Where *eventName* is the event name that will appear on your dashboard, and data is a Dictionary with your custom event data.

### Click
```swift
ExposeBox.shared.click(placementId: "ID", widgetId: INT, productId: "ID", additionalData: ["CUSTOM": "DATA"])
```
### Real Impressions
```swift
let batches = [RealImpressionBatch(placementId: "ID", widgetId: INT, items: ["CUSTOM" : "DATA"])]

ExposeBox.shared.realImpression(batches)
```
### Order (Conversions)
Notifies ExposeBox that a conversion was made. This should be sent when a conversion event has occurred (e.g. a “thank you” page after checkout)

First, create the cart products that were in the order, then send it through ExposeBox with *orderId* and *totalPrice* (optional) (*orderId* should be your order ID, which you usually get after an order was placed).
```swift
let products = [CartProduct(productId: "ID", quantity: INT, unitPrice: FLOAT)]

ExposeBox.shared.conversion(orderId: "ID", totalPrice: FLOAT, cartProducts: products)
```
### Get Recommendations
After you set up your placements in the ExposeBox dashboard, you can get product recommendations for those placements. Provide placement IDs in a string array, like in the example below for placements ID1 and ID2. The response will contain a List of ExposeBox Placements
```swift
ExposeBox.shared.recommendations(placementIds: ["ID1", "ID2"]) { objects, error in
  // YOUR HANDLERS
}
```

## Author

Viktor Shchepanovskyi, viktor.shchepanovskyi@market.com

## License

ExposeBox is available under the MIT license. See the LICENSE file for more info.
