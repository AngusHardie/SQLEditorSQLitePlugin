/*
 *  SQLObjectContainer.h
 *  SQLEditorUniversal2
 *
 *  Created by Angus W Hardie on 12/05/2008.
 *  Copyright 2008 MalcolmHardie Solutions Ltd. All rights reserved.
 *
 */

@protocol SQLObjectContainer


- (NSEnumerator*)objectListEnumerator;
- (NSArray*)objectList;
@end