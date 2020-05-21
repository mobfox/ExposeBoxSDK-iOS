#if 0
#elif defined(__arm64__) && __arm64__
// Generated by Apple Swift version 5.2.4 (swiftlang-1103.0.32.9 clang-1103.0.32.53)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <Foundation/Foundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(ns_consumed)
# define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
#else
# define SWIFT_RELEASES_ARGUMENT
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if !defined(IBSegueAction)
# define IBSegueAction
#endif
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import Foundation;
@import ObjectiveC;
@import UIKit;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="ExposeBoxSDK",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

@class ExposeBoxCompliance;

/// ExposeBox SDK class, use <em>shared</em>, <em>companyId</em> is required to send data
SWIFT_CLASS("_TtC12ExposeBoxSDK9ExposeBox")
@interface ExposeBox : NSObject
/// ExposeBox SDK class <em>shared instance</em>, <em>companyId</em> is required to send data
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) ExposeBox * _Nonnull shared;)
+ (ExposeBox * _Nonnull)shared SWIFT_WARN_UNUSED_RESULT;
/// ExposeBox company identifier, <em>companyId</em> is required to send data
@property (nonatomic, copy) NSString * _Nullable companyId;
/// ExposeBox company identifier of <em>application</em> in scope. As example <em>iOS</em> or <em>Android</em>, etc.
@property (nonatomic, copy) NSString * _Nullable appId;
/// Set <em>true</em> if you want to see more information about data sent in system logs.
/// <em>Don’t use in release versions.</em>
@property (nonatomic) BOOL versboseLogging;
/// Set if your app is compliant with GDPR, COPPA, and/or CCPA
@property (nonatomic, strong) ExposeBoxCompliance * _Nonnull compliance;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end



@class ExposeBoxCustomerData;
@class ExposeBoxCartProduct;
@class ExposeBoxRealImpressionBatch;
@class ExposeBoxPlacement;

@interface ExposeBox (SWIFT_EXTENSION(ExposeBoxSDK))
/// View event, send when item (or screen) is viewed,
/// alternatively can be used as <em>reportExposeBoxView(name: String)</em> in <em>UIViewController</em>
/// \param name name of item or screen
///
- (void)viewWithName:(NSString * _Nonnull)name;
/// View event, send <em>products</em> which were viewed
/// \param products array of Product identifiers
///
- (void)setProducts:(NSArray<NSString *> * _Nonnull)products;
/// View event, send <em>categories</em>
/// \param categories array of Category identifiers
///
- (void)setCategories:(NSArray<NSString *> * _Nonnull)categories;
/// View event, send Tags
/// \param tags dictionary with String <em>keys</em> and Array of String as <em>values</em>
///
- (void)setTags:(NSDictionary<NSString *, NSArray<NSString *> *> * _Nonnull)tags;
/// Add products to cart
/// \param productId identifier of Product
///
/// \param quantity number of items
///
/// \param unitPrice price per item
///
- (void)addToCartWithProductId:(NSString * _Nonnull)productId quantity:(NSInteger)quantity unitPrice:(float)unitPrice;
/// Remove products from cart
/// \param productId identifier of Product
///
/// \param quantity number of items
///
- (void)removeFromCartWithProductId:(NSString * _Nonnull)productId quantity:(NSInteger)quantity;
/// Send customer data information
/// \param data ExposeBoxCustomerData with customer data fields
///
- (void)setCustomerData:(ExposeBoxCustomerData * _Nonnull)data;
/// Order complete / placed, conversion event
/// \param orderId identifier of Order
///
/// \param totalPrice Total price of Items
///
/// \param cartProducts Array of Products purchased
///
- (void)conversionWithOrderId:(NSString * _Nonnull)orderId totalPrice:(float)totalPrice cartProducts:(NSArray<ExposeBoxCartProduct *> * _Nonnull)cartProducts;
/// Custom event
/// \param name name of event
///
/// \param data dictionary with event information
///
- (void)eventWithName:(NSString * _Nonnull)name data:(NSDictionary<NSString *, NSObject *> * _Nonnull)data;
/// Click event
/// \param placementId identifier of Placement
///
/// \param widgetId identifier of Widget
///
/// \param productId identifier of Product
///
/// \param additionalData additional information
///
- (void)clickWithPlacementId:(NSString * _Nonnull)placementId widgetId:(NSInteger)widgetId productId:(NSString * _Nonnull)productId additionalData:(id _Nullable)additionalData;
/// Send array of impression events, look at <em>RealImpressionBatch</em> to fill contents
/// \param batches array of <em>RealImpressionBatch</em>
///
- (void)realImpression:(NSArray<ExposeBoxRealImpressionBatch *> * _Nonnull)batches;
/// Request recommendations for user
/// \param placementIds array of placement identifiers
///
/// \param completion handler for received response data
///
- (void)recommendationsWithPlacementIds:(NSArray<NSString *> * _Nonnull)placementIds completion:(void (^ _Nonnull)(NSArray<ExposeBoxPlacement *> * _Nullable, NSError * _Nullable))completion;
/// Request recommendations for user, result as raw
/// \param placementIds array of placement identifiers
///
/// \param completion handler for received response data
///
- (void)recommendationsDataWithPlacementIds:(NSArray<NSString *> * _Nonnull)placementIds completion:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))completion;
/// Add product to <em>Wishlist</em>
/// \param productId identifier of Product
///
- (void)addToWishlistWithProductId:(NSString * _Nonnull)productId;
/// Remove product from <em>Wishlist</em>
/// \param productId identifier of Product
///
- (void)removeFromWishlistWithProductId:(NSString * _Nonnull)productId;
/// Approve <em>Coupon</em>
/// \param coupon identifier of Coupon
///
- (void)approveWithCoupon:(NSString * _Nonnull)coupon;
/// Request <em>Coupon</em>
/// \param coupon identifier of Coupon
///
- (void)requestWithCoupon:(NSString * _Nonnull)coupon;
@end


/// Object for cart product representation
SWIFT_CLASS("_TtC12ExposeBoxSDK20ExposeBoxCartProduct")
@interface ExposeBoxCartProduct : NSObject
/// Object for cart product representation
/// \param productId Identifier of product
///
/// \param quantity Quantity of products
///
/// \param unitPrice Price per Unit
///
- (nonnull instancetype)initWithProductId:(NSString * _Nonnull)productId quantity:(NSInteger)quantity unitPrice:(float)unitPrice OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC12ExposeBoxSDK19ExposeBoxCompliance")
@interface ExposeBoxCompliance : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


/// Data container for Customer data
SWIFT_CLASS("_TtC12ExposeBoxSDK21ExposeBoxCustomerData")
@interface ExposeBoxCustomerData : NSObject
/// Data container for Customer data
/// \param email Customer email
///
- (nonnull instancetype)initWithEmail:(NSString * _Nonnull)email OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


/// Object for placement with products, recommendations response
SWIFT_CLASS("_TtC12ExposeBoxSDK18ExposeBoxPlacement")
@interface ExposeBoxPlacement : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


/// Batch object to group real impression objects
SWIFT_CLASS("_TtC12ExposeBoxSDK28ExposeBoxRealImpressionBatch")
@interface ExposeBoxRealImpressionBatch : NSObject
/// Batch object to group real impression objects
/// \param placementId Identifier of placement
///
/// \param widgetId Identifier of widget
///
/// \param items Items key value pairs
///
- (nonnull instancetype)initWithPlacementId:(NSString * _Nonnull)placementId widgetId:(NSInteger)widgetId items:(NSArray<NSDictionary<NSString *, NSString *> *> * _Nonnull)items OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end






@interface UIViewController (SWIFT_EXTENSION(ExposeBoxSDK))
/// Send view event for view with name
/// \param name name of view / screen / item.
///
- (void)reportExposeBoxViewWithName:(NSString * _Nonnull)name;
@end

#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop

#elif defined(__ARM_ARCH_7A__) && __ARM_ARCH_7A__
// Generated by Apple Swift version 5.2.4 (swiftlang-1103.0.32.9 clang-1103.0.32.53)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <Foundation/Foundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(ns_consumed)
# define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
#else
# define SWIFT_RELEASES_ARGUMENT
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if !defined(IBSegueAction)
# define IBSegueAction
#endif
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import Foundation;
@import ObjectiveC;
@import UIKit;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="ExposeBoxSDK",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

@class ExposeBoxCompliance;

/// ExposeBox SDK class, use <em>shared</em>, <em>companyId</em> is required to send data
SWIFT_CLASS("_TtC12ExposeBoxSDK9ExposeBox")
@interface ExposeBox : NSObject
/// ExposeBox SDK class <em>shared instance</em>, <em>companyId</em> is required to send data
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) ExposeBox * _Nonnull shared;)
+ (ExposeBox * _Nonnull)shared SWIFT_WARN_UNUSED_RESULT;
/// ExposeBox company identifier, <em>companyId</em> is required to send data
@property (nonatomic, copy) NSString * _Nullable companyId;
/// ExposeBox company identifier of <em>application</em> in scope. As example <em>iOS</em> or <em>Android</em>, etc.
@property (nonatomic, copy) NSString * _Nullable appId;
/// Set <em>true</em> if you want to see more information about data sent in system logs.
/// <em>Don’t use in release versions.</em>
@property (nonatomic) BOOL versboseLogging;
/// Set if your app is compliant with GDPR, COPPA, and/or CCPA
@property (nonatomic, strong) ExposeBoxCompliance * _Nonnull compliance;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end



@class ExposeBoxCustomerData;
@class ExposeBoxCartProduct;
@class ExposeBoxRealImpressionBatch;
@class ExposeBoxPlacement;

@interface ExposeBox (SWIFT_EXTENSION(ExposeBoxSDK))
/// View event, send when item (or screen) is viewed,
/// alternatively can be used as <em>reportExposeBoxView(name: String)</em> in <em>UIViewController</em>
/// \param name name of item or screen
///
- (void)viewWithName:(NSString * _Nonnull)name;
/// View event, send <em>products</em> which were viewed
/// \param products array of Product identifiers
///
- (void)setProducts:(NSArray<NSString *> * _Nonnull)products;
/// View event, send <em>categories</em>
/// \param categories array of Category identifiers
///
- (void)setCategories:(NSArray<NSString *> * _Nonnull)categories;
/// View event, send Tags
/// \param tags dictionary with String <em>keys</em> and Array of String as <em>values</em>
///
- (void)setTags:(NSDictionary<NSString *, NSArray<NSString *> *> * _Nonnull)tags;
/// Add products to cart
/// \param productId identifier of Product
///
/// \param quantity number of items
///
/// \param unitPrice price per item
///
- (void)addToCartWithProductId:(NSString * _Nonnull)productId quantity:(NSInteger)quantity unitPrice:(float)unitPrice;
/// Remove products from cart
/// \param productId identifier of Product
///
/// \param quantity number of items
///
- (void)removeFromCartWithProductId:(NSString * _Nonnull)productId quantity:(NSInteger)quantity;
/// Send customer data information
/// \param data ExposeBoxCustomerData with customer data fields
///
- (void)setCustomerData:(ExposeBoxCustomerData * _Nonnull)data;
/// Order complete / placed, conversion event
/// \param orderId identifier of Order
///
/// \param totalPrice Total price of Items
///
/// \param cartProducts Array of Products purchased
///
- (void)conversionWithOrderId:(NSString * _Nonnull)orderId totalPrice:(float)totalPrice cartProducts:(NSArray<ExposeBoxCartProduct *> * _Nonnull)cartProducts;
/// Custom event
/// \param name name of event
///
/// \param data dictionary with event information
///
- (void)eventWithName:(NSString * _Nonnull)name data:(NSDictionary<NSString *, NSObject *> * _Nonnull)data;
/// Click event
/// \param placementId identifier of Placement
///
/// \param widgetId identifier of Widget
///
/// \param productId identifier of Product
///
/// \param additionalData additional information
///
- (void)clickWithPlacementId:(NSString * _Nonnull)placementId widgetId:(NSInteger)widgetId productId:(NSString * _Nonnull)productId additionalData:(id _Nullable)additionalData;
/// Send array of impression events, look at <em>RealImpressionBatch</em> to fill contents
/// \param batches array of <em>RealImpressionBatch</em>
///
- (void)realImpression:(NSArray<ExposeBoxRealImpressionBatch *> * _Nonnull)batches;
/// Request recommendations for user
/// \param placementIds array of placement identifiers
///
/// \param completion handler for received response data
///
- (void)recommendationsWithPlacementIds:(NSArray<NSString *> * _Nonnull)placementIds completion:(void (^ _Nonnull)(NSArray<ExposeBoxPlacement *> * _Nullable, NSError * _Nullable))completion;
/// Request recommendations for user, result as raw
/// \param placementIds array of placement identifiers
///
/// \param completion handler for received response data
///
- (void)recommendationsDataWithPlacementIds:(NSArray<NSString *> * _Nonnull)placementIds completion:(void (^ _Nonnull)(id _Nullable, NSError * _Nullable))completion;
/// Add product to <em>Wishlist</em>
/// \param productId identifier of Product
///
- (void)addToWishlistWithProductId:(NSString * _Nonnull)productId;
/// Remove product from <em>Wishlist</em>
/// \param productId identifier of Product
///
- (void)removeFromWishlistWithProductId:(NSString * _Nonnull)productId;
/// Approve <em>Coupon</em>
/// \param coupon identifier of Coupon
///
- (void)approveWithCoupon:(NSString * _Nonnull)coupon;
/// Request <em>Coupon</em>
/// \param coupon identifier of Coupon
///
- (void)requestWithCoupon:(NSString * _Nonnull)coupon;
@end


/// Object for cart product representation
SWIFT_CLASS("_TtC12ExposeBoxSDK20ExposeBoxCartProduct")
@interface ExposeBoxCartProduct : NSObject
/// Object for cart product representation
/// \param productId Identifier of product
///
/// \param quantity Quantity of products
///
/// \param unitPrice Price per Unit
///
- (nonnull instancetype)initWithProductId:(NSString * _Nonnull)productId quantity:(NSInteger)quantity unitPrice:(float)unitPrice OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC12ExposeBoxSDK19ExposeBoxCompliance")
@interface ExposeBoxCompliance : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


/// Data container for Customer data
SWIFT_CLASS("_TtC12ExposeBoxSDK21ExposeBoxCustomerData")
@interface ExposeBoxCustomerData : NSObject
/// Data container for Customer data
/// \param email Customer email
///
- (nonnull instancetype)initWithEmail:(NSString * _Nonnull)email OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


/// Object for placement with products, recommendations response
SWIFT_CLASS("_TtC12ExposeBoxSDK18ExposeBoxPlacement")
@interface ExposeBoxPlacement : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


/// Batch object to group real impression objects
SWIFT_CLASS("_TtC12ExposeBoxSDK28ExposeBoxRealImpressionBatch")
@interface ExposeBoxRealImpressionBatch : NSObject
/// Batch object to group real impression objects
/// \param placementId Identifier of placement
///
/// \param widgetId Identifier of widget
///
/// \param items Items key value pairs
///
- (nonnull instancetype)initWithPlacementId:(NSString * _Nonnull)placementId widgetId:(NSInteger)widgetId items:(NSArray<NSDictionary<NSString *, NSString *> *> * _Nonnull)items OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end






@interface UIViewController (SWIFT_EXTENSION(ExposeBoxSDK))
/// Send view event for view with name
/// \param name name of view / screen / item.
///
- (void)reportExposeBoxViewWithName:(NSString * _Nonnull)name;
@end

#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop

#endif
