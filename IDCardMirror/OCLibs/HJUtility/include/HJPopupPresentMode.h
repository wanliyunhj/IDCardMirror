
#import <UIKit/UIKit.h>

typedef enum {
    AnimationStyle_None,
    AnimationStyle_EraseDown,
    AnimationStyle_EraseUp,
    AnimationStyle_JumpOut1,
    AnimationStyle_JumpOut2,
    AnimationStyle_FadeOut,
    AnimationStyle_FadeIn
} AnimationStyle;

@protocol HJPopupPresentModeDelegate <NSObject>

@optional

- (void)maskTouchUpInside;

- (void)willPresentPopView;
- (void)didPresentPopView;

- (void)willDismissPopView;
- (void)didDismissPopView;

@end

@interface HJPopupPresentMode : NSObject

@property (nonatomic, weak) UIView *superView;
@property (nonatomic, strong) UIButton *maskView;
@property (nonatomic, weak) UIView *popupView;
@property (nonatomic, weak) id <HJPopupPresentModeDelegate> delegate;

- (id)initWithSuperView:(UIView *)superView withPopupView:(UIView *)popupView withMaskViewColor:(UIColor *)maskViewColor withDelegate:(id)delegate;

- (void)popupViewWithPopAnimationStyle:(AnimationStyle)popStyle;
- (void)takebackViewWithTakebackAnimationStyle:(AnimationStyle)takeBackStyle;

@end
