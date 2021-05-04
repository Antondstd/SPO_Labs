//
// Created by ad3st on 29.04.2021.
//

#ifndef LAB1FINAL_HFS_STRUCTURES_H
#define LAB1FINAL_HFS_STRUCTURES_H
#include <byteswap.h>
#include <stdint.h>

#define HFS_PLUS_SIGNATURE 0x482b
#define HFS_PLUS_VERSION 4

typedef uint16_t UniChar;

enum BTreeType {
    typeAllocation = 0,
    typeExtent = 1,
    typeCatalog = 2,
    typeAttributes = 3,
    typeStartup = 4
};

enum {
    kHFSRootParentID = 1,
    kHFSRootFolderID = 2,
    kHFSExtentsFileID = 3,
    kHFSCatalogFileID = 4,
    kHFSBadBlockFileID = 5,
    kHFSAllocationFileID = 6,
    kHFSStartupFileID = 7,
    kHFSAttributesFileID = 8,
    kHFSRepairCatalogFileID = 14,
    kHFSBogusExtentFileID = 15,
    kHFSFirstUserCatalogNodeID = 16
};

enum {
    kHFSPlusFolderRecord = 0x0001,
    kHFSPlusFileRecord = 0x0002,
    kHFSPlusFolderThreadRecord = 0x0003,
    kHFSPlusFileThreadRecord = 0x0004
};

//HFS+ data structures
struct HFSUniStr255 {
    uint16_t length;
    UniChar unicode[255];
}__attribute__((packed));
typedef struct HFSUniStr255 HFSUniStr255;
typedef const HFSUniStr255 *ConstHFSUniStr255Param;

void reverseHFSUniStr255(HFSUniStr255 *s);

struct HFSPlusBSDInfo {
    uint32_t ownerID;
    uint32_t groupID;
    uint8_t adminFlags;
    uint8_t ownerFlags;
    uint16_t fileMode;
    union {
        uint32_t iNodeNum;
        uint32_t linkCount;
        uint32_t rawDevice;
    } special;
}__attribute__((packed));
typedef struct HFSPlusBSDInfo HFSPlusBSDInfo;

void reverseHFSPlusBSDInfo(HFSPlusBSDInfo *s);

struct HFSPlusExtentDescriptor {
    uint32_t startBlock;
    uint32_t blockCount;
}__attribute__((packed));
typedef struct HFSPlusExtentDescriptor HFSPlusExtentDescriptor;
typedef HFSPlusExtentDescriptor HFSPlusExtentRecord[8];

void reverseHFSPlusExtentDescriptor(HFSPlusExtentDescriptor *s);

struct HFSPlusForkData {
    uint64_t logicalSize;
    uint32_t clumpSize;
    uint32_t totalBlocks;
    HFSPlusExtentRecord extents;
}__attribute__((packed));
typedef struct HFSPlusForkData HFSPlusForkData;
typedef uint32_t HFSCatalogNodeID;

void reverseHFSPlusForkData(HFSPlusForkData *s);

struct HFSPlusVolumeHeader {
    uint16_t signature;
    uint16_t version;
    uint32_t attributes;
    uint32_t lastMountedVersion;
    uint32_t journalInfoBlock;

    uint32_t createDate;
    uint32_t modifyDate;
    uint32_t backupDate;
    uint32_t checkedDate;

    uint32_t fileCount;
    uint32_t folderCount;

    uint32_t blockSize;
    uint32_t totalBlocks;
    uint32_t freeBlocks;

    uint32_t nextAllocation;
    uint32_t rsrcClumpSize;
    uint32_t dataClumpSize;
    HFSCatalogNodeID nextCatalogID;

    uint32_t writeCount;
    uint64_t encodingsBitmap;

    uint32_t finderInfo[8];

    HFSPlusForkData allocationFile;
    HFSPlusForkData extentsFile;
    HFSPlusForkData catalogFile;
    HFSPlusForkData attributesFile;
    HFSPlusForkData startupFile;
}__attribute__((packed));
typedef struct HFSPlusVolumeHeader HFSPlusVolumeHeader;

void reverseHFSPlusVolumeHeader(HFSPlusVolumeHeader *s);

struct BTNodeDescriptor {
    uint32_t fLink;
    uint32_t bLink;
    int8_t kind;
    uint8_t height;
    uint16_t numRecords;
    uint16_t reserved;
}__attribute__((packed));
typedef struct BTNodeDescriptor BTNodeDescriptor;

void reverseBTNodeDescriptor(BTNodeDescriptor *s);

struct BTHeaderRec {
    uint16_t treeDepth;
    uint32_t rootNode;
    uint32_t leafRecords;
    uint32_t firstLeafNode;
    uint32_t lastLeafNode;
    uint16_t nodeSize;
    uint16_t maxKeyLength;
    uint32_t totalNodes;
    uint32_t freeNodes;
    uint16_t reserved1;
    uint32_t clumpSize;
    uint8_t btreeType;
    uint8_t keyCompareType;
    uint32_t attributes;
    uint32_t reserved3[16];
}__attribute__((packed));
typedef struct BTHeaderRec BTHeaderRec;

void reverseBTHeaderRec(BTHeaderRec *s);

struct HFSPlusCatalogKey {
    uint16_t keyLength;
    HFSCatalogNodeID parentID;
    HFSUniStr255 nodeName;
}__attribute__((packed));
typedef struct HFSPlusCatalogKey HFSPlusCatalogKey;

void reverseHFSPlusCatalogKey(HFSPlusCatalogKey *s);


struct HFSPlusCatalogFolder {
    int16_t recordType;
    uint16_t flags;
    uint32_t valence;
    HFSCatalogNodeID folderID;
    uint32_t createDate;
    uint32_t contentModDate;
    uint32_t attributeModDate;
    uint32_t accessDate;
    uint32_t backupDate;
    HFSPlusBSDInfo permissions;
    uint32_t userInfo[4];
    uint32_t finderInfo[4];
    uint32_t textEncoding;
    uint32_t reserved;
}__attribute__((packed));
typedef struct HFSPlusCatalogFolder HFSPlusCatalogFolder;

void reverseHFSPlusCatalogFolder(HFSPlusCatalogFolder *s);

struct HFSPlusCatalogFile {
    int16_t recordType;
    uint16_t flags;
    uint32_t reserved1;
    HFSCatalogNodeID fileID;
    uint32_t createDate;
    uint32_t contentModDate;
    uint32_t attributeModDate;
    uint32_t accessDate;
    uint32_t backupDate;
    HFSPlusBSDInfo permissions;
    uint32_t userInfo[4];
    uint32_t finderInfo[4];
    uint32_t textEncoding;
    uint32_t reserved2;

    HFSPlusForkData dataFork;
    HFSPlusForkData resourceFork;
}__attribute__((packed));
typedef struct HFSPlusCatalogFile HFSPlusCatalogFile;

void reverseHFSPlusCatalogFile(HFSPlusCatalogFile *s);
#endif //LAB1FINAL_HFS_STRUCTURES_H
