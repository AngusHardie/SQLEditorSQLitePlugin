//
//  SQLDataType.h
//  SQLEditorUniversal2
//
//  Created by Angus W Hardie on 30/05/2008.
//  Copyright 2008 MalcolmHardie Solutions Ltd. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface SQLDataType : NSObject {

    NSString* _baseType;
    NSString* _typeSize;
}

//+ (SQLDataType*)dataType;


+ (SQLDataType*)dataTypeWithString:(NSString*)originalTypeString size:(NSString*)originalSizeString withDialect:(id)exportDialect;

+ (SQLDataType*)dataTypeWithString:(NSString*)originalTypeString withDialect:(id)exportDialect;

- (id)init;
- (id)initWithString:(NSString*)inputString size:(NSString*)size dialect:(NSString*)dialect;

- (NSString *)baseType;
- (void)setBaseType:(NSString *)value;

- (NSString *)typeSize;
- (void)setTypeSize:(NSString *)value;

- (BOOL)hasTypeSize;

- (void)setFromType:(NSString*)originalTypeString size:(NSString*)originalSizeString withDialect:(id)exportDialect;
- (void)setFromType:(NSString*)originalTypeString withDialect:(id)exporter;


- (NSString*)typeString;
@end
