//
//  SQLPrefs.h
//  SQLEditor
//
//  Created by Angus Hardie on 18/08/2004.
//  Copyright 2004 MalcolmHardie Software/Angus W Hardie. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "MHColorPrefSupport.h"
/**
	Controller for application preferences system
**/
@interface SQLPrefs : NSObject {
	NSMutableDictionary* colorKeyDictionary;
	
}
+ (SQLPrefs*)sharedPrefs;
- (NSColor*) colorForKey:(NSString*)key;
- (void) setColor:(NSColor*)aColor forKey:(NSString*)key;
- (void) setDefaultColor:(NSColor*)aColor forKey:(NSString*)key;
- (id) init;
@end
