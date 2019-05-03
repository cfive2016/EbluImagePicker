#import <UIKit/UIKit.h>
#import <Photos/Photos.h>

@class EbluImagePickerController;

@protocol EbluImagePickerControllerDelegate <NSObject>

@optional
- (void)eblu_imagePickerController:(EbluImagePickerController *)imagePickerController didFinishPickingAssets:(NSArray *)assets;
- (void)eblu_imagePickerControllerDidCancel:(EbluImagePickerController *)imagePickerController;

- (BOOL)eblu_imagePickerController:(EbluImagePickerController *)imagePickerController shouldSelectAsset:(PHAsset *)asset;
- (void)eblu_imagePickerController:(EbluImagePickerController *)imagePickerController didSelectAsset:(PHAsset *)asset;
- (void)eblu_imagePickerController:(EbluImagePickerController *)imagePickerController didDeselectAsset:(PHAsset *)asset;

@end

typedef NS_ENUM(NSUInteger, EbluImagePickerMediaType) {
    EbluImagePickerMediaTypeAny = 0,
    EbluImagePickerMediaTypeImage,
    EbluImagePickerMediaTypeVideo
};

@interface EbluImagePickerController : UINavigationController

@property (nonatomic, weak) id<EbluImagePickerControllerDelegate> imagePickerDelegate;
@property (nonatomic, strong) UIColor *themeColor;

@property (nonatomic, strong, readonly) NSMutableOrderedSet *selectedAssets;

@property (nonatomic, copy) NSArray *assetCollectionSubtypes;
@property (nonatomic) EbluImagePickerMediaType mediaType;

@property (nonatomic) BOOL allowsMultipleSelection;
@property (nonatomic) NSUInteger minimumNumberOfSelection;
@property (nonatomic) NSUInteger maximumNumberOfSelection;

@property (nonatomic, copy) NSString *prompt;
@property (nonatomic) BOOL showsNumberOfSelectedAssets;

@property (nonatomic) NSUInteger numberOfColumnsInPortrait;
@property (nonatomic) NSUInteger numberOfColumnsInLandscape;

@end
