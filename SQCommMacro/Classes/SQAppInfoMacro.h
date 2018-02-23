//
//  SQAppInfoMacro.h
//  SQCommMacro
//
//  Created by liaoyp on 2018/2/23.
//  Copyright © 2018年 SQKB. All rights reserved.
//

#ifndef SQAppInfoMacro_h
#define SQAppInfoMacro_h

/// Log
static inline void CPLog(NSString *format, ...) {
#ifdef DEBUG
    va_list argptr;
    va_start(argptr, format);
    NSLogv(format, argptr);
    va_end(argptr);
#endif
}

#ifdef DEBUG
#define DLog(format, ...)       NSLog(@"%s(%d行): " format, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define DLog(format, ...)
#endif

#ifdef DEBUG
#define NSLog(FORMAT, ...)      fprintf(stderr,"%s:%d\t%s\n",[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define NSLog(...)
#endif


/// G－C－D 便捷调用
#define BACK(block)             dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define MAIN(block)             dispatch_async(dispatch_get_main_queue(),block)
#define AFTER(time, block)      dispatch_after(dispatch_time(DISPATCH_TIME_NOW, time * NSEC_PER_SEC), dispatch_get_main_queue(), block);

/// APP 信息
#define kDeviceName             [[UIDevice currentDevice] name]
#define kSystemName             [[UIDevice currentDevice] systemName]   // e.g. @"iOS"
#define kSystemVersion          [[UIDevice currentDevice] systemVersion]
#define kDeviceModel            [[UIDevice currentDevice] model]        // @"iPhone", @"iPod touch"
#define InfoDictionary          [[NSBundle mainBundle] infoDictionary]
#define kAppName                [InfoDictionary objectForKey:@"CFBundleDisplayName"]
#define kAppVersion             [InfoDictionary objectForKey:@"CFBundleShortVersionString"]
#define kBoundleId              [InfoDictionary objectForKey:(NSString*)kCFBundleIdentifierKey]

/// UserDefault
#define SQUserDefaults           [NSUserDefaults standardUserDefaults]

/// 字体
#define FONT(F)                 [UIFont systemFontOfSize:F]
#define BOldFONT(F)             [UIFont boldSystemFontOfSize:F]

/// 颜色
#define RGB(x,y,z)              [UIColor colorWithRed:(x)/255.0 green:(y)/255.0 blue:(z)/255.0 alpha:1.0]
#define RGBA(x,y,z,a)           [UIColor colorWithRed:(x)/255.0 green:(y)/255.0 blue:(z)/255.0 alpha:a]
#define ColorFromImageName(n)   [UIColor colorWithPatternImage:[UIImage imageNamed:n]]

/// 颜色
#define kColorTableBg           RGB(246, 246, 246) // 244
#define kColorImageBg           RGB(230, 230, 230)
#define kColorLine              RGB(246, 246, 246)
#define kColorTitle             RGB(6, 27, 40)
#define kColorTitle68           RGB(68, 68, 68) // not use.
#define kColorCellTitle         RGB(85, 85, 85)
#define kColorText              RGB(102, 102, 102)
#define kColorContentText       RGB(153, 153, 153)
#define kColorPlaceHolder       RGB(153, 153, 153)
#define kColorDefaultRed        RGB(253, 99, 99)
#define kColorDarkRed           RGB(255, 34, 32)

/// int 转字符串
#define StringFromInt(int)      [NSString stringWithFormat:@"%ld",int]

/// 空值判断相关
#define IsEmpty(str)            (str == nil || ![str respondsToSelector:@selector(isEqualToString:)] || [str isEqualToString:@""])
#define IsNull(obj)             (obj == nil || [obj isEqual:[NSNull null]])
#define IsArray(obj)            (obj && [obj isKindOfClass:[NSArray class]] && [obj count])
#define IsDictionary(obj)       (obj && [obj isKindOfClass:[NSDictionary class]] && [obj count])

/// Block self
#define SQWeakSelf                typeof(self) __weak weakSelf = self;
#define SQStrongSelf              typeof(weakSelf) __strong strongSelf = weakSelf;

/// YYModel encode
#define BTModelSynthCoderAndHash \
- (void)encodeWithCoder:(NSCoder *)aCoder { [self yy_modelEncodeWithCoder:aCoder]; } \
- (id)initWithCoder:(NSCoder *)aDecoder { return [self yy_modelInitWithCoder:aDecoder]; } \
- (id)copyWithZone:(NSZone *)zone { return [self yy_modelCopy]; }


#endif /* SQAppInfoMacro_h */
