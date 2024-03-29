//
//  CaulyNativeAd.h
//  CaulySDK
//
//  Created by FSN on 10/23/23.
//

#import <Foundation/Foundation.h>

#import <CaulySDK/CaulyAdSetting.h>
#import <CaulySDK/CaulyNativeAdItem.h>

@class CaulyNativeAd;

// Cauly 광고 이벤트 Delegate
@protocol CaulyNativeAdDelegate <NSObject>

@optional

// 광고 정보 수신 성공
- (void)didReceiveNativeAd:(CaulyNativeAd *)nativeAd isChargeableAd:(BOOL)isChargeableAd;

// 광고 정보 수신 실패
- (void)didFailToReceiveNativeAd:(CaulyNativeAd *)nativeAd errorCode:(int)errorCode errorMsg:(NSString *)errorMsg;


@end


@interface CaulyNativeAd : NSObject


+ (id)caulyNativeAdWithController:(UIViewController *)controller;
- (id)initWithParentViewController:(UIViewController *)controller;

- (void)startNativeAdRequest:(int) adListSize nativeAdComponentType:(CaulyNativeAdComponentType) nativeAdComponentType imageSize:(NSString*) imageSize;
- (CaulyNativeAdItem*) nativeAdItemAt:(int) index;
- (NSArray*) nativeAdItemList;
- (void) sendInform:(CaulyNativeAdItem*) nativeAdItem;
- (void) click:(CaulyNativeAdItem*) nativeAdItem;
- (void) sendToOptOutLinkUrl :(CaulyNativeAdItem*) nativeAdItem;
- (void) stopAdRequest;

@property (nonatomic, weak) UIViewController * parentController;
@property (nonatomic, weak) id<CaulyNativeAdDelegate> delegate;
@property (nonatomic, strong) CaulyAdSetting * localSetting;
@property (nonatomic, strong) NSObject * data;

@property (nonatomic, readonly) NSString * errorMsg;

@end
