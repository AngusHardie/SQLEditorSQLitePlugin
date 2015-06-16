/*
 *  TypeMatchingManager.h
 *  SQLEditorUniversal
 *
 *  Created by Angus Hardie on 20/12/2006.
 *  Copyright 2006 MalcolmHardie Solutions Ltd.. All rights reserved.
 *
 */

@interface TypeMatchingManager : NSObject {
	id _typeMatchingHash;
}

+ (TypeMatchingManager*)sharedTypeMatchingManager;

- (BOOL)isTypeEquivalent:(NSString*)type1 :(NSString*)type2;

@end;