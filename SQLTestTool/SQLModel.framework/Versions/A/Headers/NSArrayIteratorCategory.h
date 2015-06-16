//
//  NSArrayIteratorCategory.h
//  SQLEditorUniversal
//
//  Created by Angus Hardie on 20/12/2006.
//  Copyright 2006 MalcolmHardie Solutions Ltd.. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "SQLIterator.h"

@interface NSArray ( NSArrayIteratorCategory ) 




- (SQLIterator*)iterator;
@end


@interface NSMutableArray  ( NSMutableArrayIteratorCategory ) 




- (SQLIterator*)iterator;
@end