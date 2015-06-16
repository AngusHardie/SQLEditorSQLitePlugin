//
//  SQLComment.h
//  SQLParser
//
//  Created by Angus W Hardie on Sun 23rd May 2004
//  Copyright (c) 2004 Malcolmhardie Software. All rights reserved.
//
#import <Cocoa/Cocoa.h>
#import "SQLField.h"
//#import "Point.h"
//#import "Dimension.h"
#import "SQLObjectPeer.h"
/**
 Interface for SQLModel.SQLComment
 **/
EXPORT_SYMBOL_EXTERNAL
@interface SQLComment : SQLObjectPeer{
	id _comment;
}


- (NSString*)getComment;
- (NSString*)comment;
- (void)setComment:(NSString*)comment;
- (id)initWithComment:(NSString*)commentString;





@end