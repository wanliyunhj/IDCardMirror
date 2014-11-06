
#import <Foundation/Foundation.h>
#import "HJImageLoader.h"

@interface HJImageLoaderBody : NSObject
{
    int index;
}

@property(nonatomic, assign) BOOL isCancelled;

- (void)cancel;

//异步获取图片，根据不同的参数做裁剪
- (void)loadImageWithLocalPath:(NSString *)localPath complete:(blockDidLoadImage)didLoadImage;
- (void)loadImageWithLocalPath:(NSString *)localPath fitScreen:(BOOL)fit complete:(blockDidLoadImage)didLoadImage;
//获取网络图片，本地没有，从网络下载
- (void)loadImageWithURL:(NSString *)url withLocalPath:(NSString *)lp complete:(blockDidLoadImage)didLoadImage;

@end
