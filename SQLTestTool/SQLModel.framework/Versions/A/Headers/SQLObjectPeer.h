// SQLObjectPeer header file
// represents objects within an SQLContainer
// that can have a visual peer

#import <Cocoa/Cocoa.h>
#import "SQLObject.h"
/**
 Interface for Model objects that have view peers
 **/
@interface SQLObjectPeer : SQLObject {
    
	
	BOOL _hasViewPeer;
	
	BOOL hasCocoa;
    
    BOOL didChangeNameDuringValidation;
}

@property (assign) BOOL didChangeNameDuringValidation;

- (NSString*)getClassType;
- (BOOL)getHasViewPeer;
- (void)setHasViewPeer:(BOOL)val;


//- (oneway void)release;


- (NSUInteger)zOrder;
- (NSUInteger)getZOrder;
- (void) setZOrder:(NSUInteger) zOrder;





- (NSString*) trimName:(NSString*) name;

+ (NSDictionary*)splitNameBySchema:(NSString*)name ;
+ (NSDictionary*) splitNameBySchema:(NSString*) originalInput splitSchema:(BOOL)splitSchema;
@end