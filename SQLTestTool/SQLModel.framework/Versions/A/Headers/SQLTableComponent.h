/*
 *  SQLTableComponent.h
 *  SQLEditorU
 *
 *  Created by Angus Hardie on 12/02/2006.
 *  Copyright 2006 MalcolmHardie Solutions Ltd. All rights reserved.
 *
 */
#import "SQLObjectPeer.h"

@class SQLDocumentInfo;

@interface SQLTableComponent : SQLObjectPeer {
    
	
	BOOL _hasCocoa;
	
	//NSString* _comment;
    
}
- (void)setName:(NSString*)name;
- (NSString*)getName;
- (NSString*)name;
- (NSString*)exportToXMLWithWrapper;

- (void)setParent:(id) parent;
- (id)getParent;
- (id)parent;

- (id)fkField; // stub method only

//- (NSString*) exportToSQLWithDocumentInfo:(SQLDocumentInfo*) documentInfo;
- (NSString*) exportToSQL:(BOOL) showReferencesInline documentInfo:(SQLDocumentInfo*) documentInfo;


- (void) clearIncompleteReferenceTargetTable;
- (void) setIncompleteReferenceTargetTable:(NSString*) referencesTable 
							referenceField:(NSString*) referencesField;
- (void) reconnectIncompleteReference;
@end