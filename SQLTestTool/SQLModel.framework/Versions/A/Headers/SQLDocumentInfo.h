/*
 *  SQLDocumentInfo.h
 *  SQLEditor
 *
 *  Created by Angus Hardie on 29/09/2004.
 *  Copyright 2004 MalcolmHardie Software/Angus W Hardie. All rights reserved.
 *
 */
#import <Cocoa/Cocoa.h>
#import "SQLObjectPeer.h"

/**
	Header for SQLModel.SQLDocumentInfo
**/
@interface SQLDocumentInfo : SQLObjectPeer {
	//NSData* _printInfo;
	NSString* _encodedPrintInfo;
	
	id document;
    
    
    NSString* lastExportFileNameStem;
    NSString* lastExportFileName;
}


@property (copy) NSString* lastExportFileNameStem;
@property (copy) NSString* lastExportFileName;

- (void)setDocument:(id)document;
- (id)document;

- (BOOL)getPageBoundariesVisible;
- (void)setPageBoundariesVisible:(BOOL)visible;

- (BOOL)getPageGridVisible;
- (void)setPageGridVisible:(BOOL)visible;

- (BOOL)getSnapToGrid;
- (void)setSnapToGrid:(BOOL)visible;


- (BOOL)getDropTableOption;
- (void)setDropTableOption:(BOOL)shouldDrop;

- (BOOL)getAutoSizeTablesOption;
- (void)setAutoSizeTablesOption:(BOOL)shouldAutoSize;

- (float)getDocumentScaleFactor;
- (void)setDocumentScaleFactor:(float)newFactor;

- (void)setDocumentScaleFactorAsString:(NSString*)newFactor;

- (void)setDocumentPrintInfo:(NSData*)pi;
- (NSData*)getDocumentPrintInfo;

- (void)setExportDialect:(NSString*)dialect;
- (NSString*)getExportDialect;
- (NSString*)exportDialect;
- (void)setDefaultExportDialect:(NSString*)dialect;

- (NSString*)getHeader;
- (void)setHeader:(NSString*)newHeader;
- (NSString*)getFooter;
- (void)setFooter:(NSString*)newFooter;

- (NSString*)getEncodedPrintInfo;
- (void)setEncodedPrintInfo:(NSString*)encodedPrintInfo;
- (NSString*)encodedPrintInfo;
@end

