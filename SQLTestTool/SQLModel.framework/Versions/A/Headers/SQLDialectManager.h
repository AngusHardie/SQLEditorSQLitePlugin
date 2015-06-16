//
//  SQLDialectManager.h
//  SQLEditorUniversal
//
//  Created by Angus W Hardie on 18/11/2007.
//  Copyright 2007 MalcolmHardie Solutions Ltd. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class SQLContainer;

@interface SQLDialectManager : NSObject {

	//id dialectList;
	
	id dialectManager;
}

+ (SQLDialectManager*)sharedDialectManager;
- (NSArray*)dialectList;
- (NSArray*)dialectList:(BOOL)showUserDisplayableOnly;

- (void)updateDialectPopup:(NSPopUpButton*)targetListMenu;
- (void)updateDialectPopup:(NSPopUpButton*)targetListMenu target:(id)target action:(SEL)action displayableOnly:(BOOL)displayableOnly;

- (NSString*)exportFileTypeForDialect:(id)dialect;

- (id)exporterForDialect:(NSString*)dialect;

- (NSString*)validFileNameForDialect:(id)dialect existingFileName:(NSString*)existingFileName preDisplay:(BOOL)preDisplay forContainer:(SQLContainer*)container;
@end
