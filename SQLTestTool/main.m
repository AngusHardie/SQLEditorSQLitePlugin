//
//  main.m
//  SQLReportGenerator
//
//  Created by Angus Hardie on 19/03/2015.
//  Copyright (c) 2015 MalcolmHardie Solutions. All rights reserved.
//



#import <Foundation/Foundation.h>

#define EXPORT_SYMBOL_EXTERNAL __attribute__((visibility("default")))

#import <SQLModel/SQLTable.h>
#import <SQLModel/SQLPluginManager.h>
#import <SQLModel/SQLContainer.h>
#import <SQLModel/GenericSQLExporter.h>
#import <SQLModel/SQLIndex.h>


@interface NSObject (plugin)
- (void)initPlugin;
- (id)exporter;
- (BOOL)importFile:(id)curFile toContainer:(SQLContainer*)container;
@end

@interface NSObject (exporter)
- (NSString*)exportContainer:(id)container withDocumentInfo:(id)documentInfo;
@end

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        
        
        
        [SQLPluginManager sharedPluginManager];
        
        NSLog(@"Plugin types = %@",[[SQLPluginManager sharedPluginManager] supportedExportTypes]);
        
        id reportPlugin = [[SQLPluginManager sharedPluginManager] exportPluginForType:@"HTML Single Page Exporter"];
        
        
        id exporter = [reportPlugin exporter];
        
        SQLContainer* container = [[SQLContainer alloc] init];
        
        SQLTable* table = [SQLTable tableWithName:@"test"];
        
        [table setSchemaName:@"A1"];
        
        [container add:table];
        
        SQLField* testField1 = [SQLField fieldWithName:@"id1" type:@"TIME"];
        [testField1 setUnique:YES];
        [table add:testField1];
        
        
        SQLField* testField3 = [SQLField fieldWithName:@"id3" type:@"VARCHAR(255)"];
        [table add:testField3];
        
        SQLField* testField4 = [SQLField fieldWithName:@"id4" type:@"SMALLINT"];
        [table add:testField4];
        
        
        SQLField* testField5 = [SQLField fieldWithName:@"id5" type:@"BIT"];
        [table add:testField5];
        
        
        SQLField* testField6 = [SQLField fieldWithName:@"id6" type:@"BIT"];
        [table add:testField6];
        
        
        SQLTable* table2 = [SQLTable tableWithName:@"test2"];
        
        [table2 setComment:@"test comments"];
        
        [container add:table2];
        
        SQLField* testField2 = [SQLField fieldWithName:@"id2" type:@"INT(2)"];
        
        [testField2 setPrimaryKey:YES];
        [testField2 setUnique:YES];
        
        [testField2 setFkField:testField1];
        [table2 add:testField2];
        
        [testField2 setComment:@"hello world"];
        
        
        [table2 add:[SQLIndex indexWithName:@"test_idx"]];
        
        
        
        NSString* result = [exporter exportContainer:container withDocumentInfo:nil];
        
        
        NSLog(@"result: %@",result);
        
    }
    return 0;
}
