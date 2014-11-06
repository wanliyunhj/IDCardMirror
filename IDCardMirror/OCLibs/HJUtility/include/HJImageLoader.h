
#import <UIKit/UIKit.h>

typedef void (^blockDidLoadImage)(UIImage *image);

@interface HJImageLoader : NSObject

//异步获取图片，根据不同的参数做裁剪
- (void)loadImageWithLocalPath:(NSString *)localPath complete:(blockDidLoadImage)didLoadImage;
- (void)loadImageWithLocalPath:(NSString *)localPath fitScreen:(BOOL)fit complete:(blockDidLoadImage)didLoadImage;
/*
- (void)loadImageWithLocalPath:(NSString *)localPath resizeRect:(CGSize)size complete:(didloadImage)blockDidLoadImage;
- (void)loadImageWithLocalPath:(NSString *)localPath scaleClipRect:(CGRect)rect complete:(didloadImage)blockDidLoadImage;
 */

//加载网络图片，如果本地存在，则返回本地图片，否则返回从网络下载该图片返回
- (void)loadImageWithURL:(NSString *)url withLocalPath:(NSString *)lp complete:(blockDidLoadImage)didLoadImage;

/*
//只读cache图片
-(UIImage *)loadCacheImageWithPath:(NSString *)localPath;
 */

@end
