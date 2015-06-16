//
//  SQLObjectLabelManager.h
//  SQLEditorUniversal4e
//
//  Created by Angus Hardie on 11/08/2009.
//  Copyright 2009 MalcolmHardie Solutions Limited. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class SQLObject;
@class SQLObjectLabel;

@interface SQLObjectLabelManager : NSObject {

	NSMutableArray* labelList;
	id container;
	
	NSMutableDictionary* tableLabelList;
}

@property (assign) id container; // will be weak when we move to 10.7
		   
- (NSMutableArray*)labelList;
- (void)loadLabelsFromManager:(SQLObjectLabelManager*)otherManager;
- (void)createLabelFromObjectIfRequired:(SQLObject*)object;
- (void)addLabel:(SQLObjectLabel*)newLabel ignoreDuplicates:(BOOL)ignoreDuplicates;
- (void)removeAllLabels;

- (void)exportLabelsToXMLNode:(NSXMLElement*)exportNode;
- (void)removeLabel:(SQLObjectLabel*)label;

- (id)tablesWithLabel:(id)label;
- (void)updateTablesWithLabelList;
- (NSDictionary*)objectCountByLabel;

- (NSMutableArray*)labelList;

- (void)removeObjectFromLabelList:(SQLObject*)object isDeleted:(BOOL)isDeleted;
- (void)addObjectToLabelList:(SQLObject*)object;
- (void)updateLabelListForObject:(SQLObject*)object;
- (void)moveObject:(id)object toPosition:(int)position;

- (void)updateLabelList;
- (void)sortLabelTable;
- (void)updateLabelListForObject:(SQLObject*)object;


- (void)postLoadProcess;

- (NSUInteger)countOfObjectsWithLabel:(SQLObjectLabel*)label;

@end
