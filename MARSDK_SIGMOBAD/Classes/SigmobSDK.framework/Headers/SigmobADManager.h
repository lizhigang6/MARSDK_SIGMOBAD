//
//  SigmobADManager.h
//  SigmobSDK
//
//  Created by 李志刚 on 2023/3/31.
//

#import <Foundation/Foundation.h>
#import <MARSDKCore/MARAd.h>
#import <WindMillSDK/WindMillSDK.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, SigmobADType) {
    SigmobADTypeRewarded,
    SigmobADTypeInterstitial,
    SigmobADTypeSplash,
    SigmobADTypeBanner,
    SigmobADTypeNativePatch
};



@interface SigmobADManager : NSObject






@property (nonatomic, strong) NSString *appID;
@property (nonatomic, strong) NSString *appKey;
@property (nonatomic, strong) NSString *rewardedKey;
@property (nonatomic, strong) NSString *interstitialKey;
@property (nonatomic, strong) NSString *splashKey;
@property (nonatomic, strong) NSString *bannerKey;

@property (nonatomic, strong) NSString *userID;

@property (nonatomic, strong) NSString *bannerHighly;
@property (nonatomic, strong) NSString *bannerWidht;
@property (nonatomic, strong) NSString *DEBUGMODEL;



@property (nonatomic, strong) NSString *native_splashId;
@property (nonatomic, strong) NSString *native_bannerId;
@property (nonatomic, strong) NSString *native_plaqueId;
@property (nonatomic, strong) NSString *native_patchId;
@property (nonatomic, strong) NSString *float_Id;

@property (nonatomic, strong) NSString *showtime;

@property (nonatomic, strong) NSString *spreadOut;

@property (nonatomic, strong) NSString *inters_shake;
@property (nonatomic, strong) NSString *splash_shake;



//竞价功能
@property (nonatomic, strong) NSString * bidding_enable;


@property id<MARAdPopupDelegate> Popupdelegate;
@property id<MARAdBannerDelegate> Bannerdelegate;
@property id<MARAdSplashDelegate> Splashdelegate;
@property id<MARAdRewardedDelegate> Rewardeddelegate;
@property id<MARAdNativeDelegate> Nativedelegate;


///  获取MARAction的单例
+(instancetype) sharedInstance;

- (void)initSDK;

- (void)NetworkInspection;

- (void)showBanner;

- (void)hideBanner;

-(void)originalPatch;

-(void)hideOriginalPatch;

- (void)showSplash;

- (void)showPatchAD;

- (void)hideNativePatch;
//   显示悬浮广告
-(void)showNativeAD:(CGPoint)Point;
//   隐藏悬浮广告
- (void) hideFloatAd;



- (void)showInterstitialWithScene:(NSString *)scene closeHandler:(void(^)(void))closeHandler;

- (void)showRewardedWithCloseHandler:(void(^)(BOOL rewarded))closeHandler;

- (void)showSpecialRewardAd;

- (void)showRewardedWithScene:(NSString *)scene closeHandler:(void(^)(BOOL rewarded))closeHandler;

- (BOOL)isReadyByType:(SigmobADType)type;

-(BOOL) adControlSwitch:(NSString *)AdID;




+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;



-(void)readycache;
-(void)handlerSigmobRewardedDelegate;

-(UIViewController *)getCurrentVC;


//WindMillAdInfo 转字典
-(NSDictionary *)adinfoToDictionary:(WindMillAdInfo *)adInfo;

@end

NS_ASSUME_NONNULL_END
