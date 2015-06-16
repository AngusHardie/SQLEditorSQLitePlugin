//
//  SQLFieldBlockEntry.h
//  SQLEditorUniversal4b
//
//  Created by Angus Hardie on 14/05/2009.
//  Copyright 2009 MalcolmHardie Solutions Limited. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface SQLFieldBlockEntry : NSObject {

	NSString* exportSQL;
	BOOL isComment;
}

+ (id)SQLFieldBlockEntry:(NSString*)sqlString isComment:(BOOL)comment;
- (id)initWithExportSQL:(NSString*)sqlString isComment:(BOOL)comment;
- (NSString *)exportSQL;
- (void)setExportSQL:(NSString *)value;

- (BOOL)isComment;
- (void)setIsComment:(BOOL)value;



@end
