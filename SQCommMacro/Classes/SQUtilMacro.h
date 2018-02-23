//
//  SQUtilMacro.h
//  SQCommMacro
//
//  Created by liaoyp on 2018/2/23.
//  Copyright © 2018年 SQKB. All rights reserved.
//

#ifndef SQUtilMacro_h
#define SQUtilMacro_h

/// 系统版本
#define IOS_VERSION_7_OR_ABOVE  (([[[UIDevice currentDevice] systemVersion] doubleValue] >= 7.0)? (YES):(NO))
#define IOS_VERSION_9_OR_ABOVE  (([[[UIDevice currentDevice] systemVersion] doubleValue] >= 9.0)? (YES):(NO))
#define IOS_VERSION_8_OR_ABOVE  (([[[UIDevice currentDevice] systemVersion] doubleValue] >= 8.0)? (YES):(NO))
#define IOS_VERSION_LESS_IOS9   (([[[UIDevice currentDevice] systemVersion] doubleValue] < 9.0)? (YES):(NO))

/// 设备
#define iPhone4                 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)
#define iPhone6                 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)
#define iPhone6Plus             ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)
#define iPhoneX                 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)
#define IPAD                    ([[UIDevice currentDevice] respondsToSelector:@selector(userInterfaceIdiom)] && [[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)

/// 屏幕frame
#define kScreenRect             [UIScreen mainScreen].bounds

/// 屏幕宽度
#define kScreenWidth            [UIScreen mainScreen].bounds.size.width

/// 屏幕高度
#define kScreenHeight           [UIScreen mainScreen].bounds.size.height

/// 屏幕scale
#define kScreenScale            [UIScreen mainScreen].scale

/// 状态栏高度
#define kStatusBarHeight        (iPhoneX ? 44 : 20)

/// 导航栏高度
#define kNavigationBarHeight    44

/// 展示的导航的高度（导航+状态栏）
#define kNavigationHeight       (kStatusBarHeight + kNavigationBarHeight)

/// 底部 tabbar 高度
#define kTabBarHeight           (49 + (iPhoneX ? 34 : 0))

/// 简单弹窗
#define kTipAlert(_S_, ...)     [[[UIAlertView alloc] initWithTitle:@"提示" message:[NSString stringWithFormat:(_S_), ##__VA_ARGS__] delegate:nil cancelButtonTitle:@"知道了" otherButtonTitles:nil] show]

/// 弃用便捷写法 attribute
#define SQ_DEPRECATED_IOS(_btVersion, ...) __attribute__((deprecated("")))

/// 不可用
#define SQ_UNAVAILABLE(message) __attribute__((unavailable(message)))


/// 是否是子类
UIKIT_STATIC_INLINE BOOL IsSubClass(id self,Class c) {
    return [self isKindOfClass:c] && ![self isMemberOfClass:c];
};

/// Window
UIKIT_STATIC_INLINE UIWindow* SQKeyWindow(){
    UIWindow * window = [[UIApplication sharedApplication] keyWindow];
    if (!window || window.windowLevel != UIWindowLevelNormal) {
        NSArray *windows = [[UIApplication sharedApplication] windows];
        for(UIWindow * tmpWin in windows) {
            if (tmpWin.windowLevel == UIWindowLevelNormal) {
                window = tmpWin;
                break;
            }
        }
    }
    return window;
}

/// floor value for pixel-aligned
UIKIT_STATIC_INLINE CGFloat SQFloatPixelFloor(CGFloat value) {
    CGFloat scale = kScreenScale;
    return floor(value * scale) / scale;
}

/// ceil value for pixel-aligned
UIKIT_STATIC_INLINE CGFloat SQFloatPixelCeil(CGFloat value) {
    CGFloat scale = kScreenScale;
    return ceil(value * scale) / scale;
}

/// round value for pixel-aligned
UIKIT_STATIC_INLINE CGFloat SQFloatPixelRound(CGFloat value) {
    CGFloat scale = kScreenScale;
    return round(value * scale) / scale;
}

/// float value from UI 750px.
UIKIT_STATIC_INLINE CGFloat SQFloatFromPixel750(CGFloat value) {
    return value/750.0 *kScreenWidth;
}

/// float value from UI 375pt.
UIKIT_STATIC_INLINE CGFloat SQFloatFromPixel375(CGFloat value) {
    return value/375.0 *kScreenWidth;
}

///// 网络连接
//#define isNotReachable          ([[Reachability reachabilityForInternetConnection] currentReachabilityStatus] == NotReachable)
//
///// 网络未连接
//#define kNotConnectNetWorkText  @"请检查你的网络连接"
//
//#define CheckNetWorkConnent     if (isNotReachable) {\
//MBShowHint(self, @"当前没有网络，请检查网络设置");\
//return;\
//}


#endif /* SQUtilMacro_h */
