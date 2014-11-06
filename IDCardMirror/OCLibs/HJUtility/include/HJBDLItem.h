
#import <Foundation/Foundation.h>

@interface HJBDLItem : NSObject{
    id curItem;
    HJBDLItem *prevItem;
    HJBDLItem *nextItem;
    NSString *key;
}

@property(nonatomic, strong) id curItem;
@property(nonatomic, strong) HJBDLItem *prevItem;
@property(nonatomic, strong) HJBDLItem *nextItem;
@property(nonatomic, strong) NSString *key;

- (id)initWithObject:(id)object forKey:(NSString *)aKey;

@end
