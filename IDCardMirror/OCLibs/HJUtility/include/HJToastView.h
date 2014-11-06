//
//  HJToastBaseView.h
//
//  Created by 胡瑨 on 14-4-19.
//  Copyright (c) 2014年 HJ. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum
{
    ToastType_Default_Success,
    ToastType_Default_Failed,
    ToastType_Custom
}ToastType;

@protocol HJToastViewDelegate <NSObject>

@optional
- (void)toastFadeOut;

@end

@interface HJToastView : UIView

@property (nonatomic, weak) id <HJToastViewDelegate> delegate;

+ (HJToastView *)toastViewWithType:(ToastType)type;

- (void)setToastText:(NSString *)text;
- (void)setToastView:(UIView *)view;

- (void)show;

@end
