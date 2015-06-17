//
//  MHMutableNotifyingPropertyDictionary.h
//  SQLEditor-17
//
//  Created by Angus Hardie on 24/08/2011.
//  Copyright 2011 MalcolmHardie Solutions Limited. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface MHMutableNotifyingPropertyDictionary : NSObject {

	NSMutableDictionary* properties;
	id ownerObject;
}

- (id)initWithModelObject:(id)theOwner;

- (void)setValue:(id)value forKey:(NSString *)key;
- (id)valueForKey:(NSString *)key;


- (id)objectForKey:(id)key;
- (void)setObject:(id)object forKey:(id)key;
- (void)removeObjectForKey:(id)key;

- (void)addEntriesFromPropertyDictionary:(MHMutableNotifyingPropertyDictionary*)newProperties;
- (void)addEntriesFromDictionary:(NSDictionary*)dictionary;

- (NSDictionary*)internalProperties;
- (NSArray*)allKeys;

@end
