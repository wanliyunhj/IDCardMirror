
#import <UIKit/UIKit.h>
#import "HJPopupPresentMode.h"

@class HJCustomAlertBaseView;

@protocol HJCustomAlertBaseViewDelegate <NSObject>

@optional

// before animation and showing view
- (void)willPresentCustomAlertView:(HJCustomAlertBaseView *)customAlertView;

// after animation
- (void)didPresentCustomAlertView:(HJCustomAlertBaseView *)customAlertView;

// before animation and hiding view
- (void)willDismissCustomAlertView:(HJCustomAlertBaseView *)customAlertView;

// after animation
- (void)didDismissCustomAlertView:(HJCustomAlertBaseView *)customAlertView;

- (void)cancelButtonClicked:(HJCustomAlertBaseView *)customAlertView;

- (void)okButtonClicked:(HJCustomAlertBaseView *)customAlertView;

@end

@interface HJCustomAlertBaseView : UIView <HJPopupPresentModeDelegate>
{
    HJPopupPresentMode * popupPresentMode;
    AnimationStyle popupStyle;
    AnimationStyle takebackStyle;
}

@property (nonatomic, weak) id <HJCustomAlertBaseViewDelegate> delegate;

- (void)constructAlertViewWithPopupAnimStyle:(AnimationStyle)popupStyle withTakebackAnimStyle:(AnimationStyle)takebackStyle withDelegate:(id)delegate;
- (void)constructAlertViewWithPopupAnimStyle:(AnimationStyle)aPopupStyle withTakebackAnimStyle:(AnimationStyle)aTakebackStyle withSuperView:(UIView *)superView withDelegate:(id)aDelegate;

- (void)show;
- (void)cancel;
- (void)ok;

- (void)dismissCustomAlertViewWithAnimated:(BOOL)animated;
- (void)dismissCustomAlertViewWithStyle:(AnimationStyle)aTakebackStyle;

@end
