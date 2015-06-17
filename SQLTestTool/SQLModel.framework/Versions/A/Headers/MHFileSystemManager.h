//
//  NSFileManagerPRAdditions.h
//  SQLEditor
//
//  Created by Angus Hardie on 29/05/2005.
//  Copyright 2005 MalcolmHardie Solutions Ltd. All rights reserved.
//
/** 
* File system utilities
*
* MHFileSystemManager wraps FSFindFolder 
**/
#import <Cocoa/Cocoa.h>

@interface MHFileSystemManager : NSObject
{
	
}
+ (MHFileSystemManager*) sharedManager;

- (NSString*)applicationSupportDirectory;
- (BOOL)createApplicationSupportDirectory;

@end

