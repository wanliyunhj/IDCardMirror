//
//  MainViewController.swift
//  IDCardMirror
//
//  Created by 胡瑨 on 14/11/6.
//  Copyright (c) 2014年 HJ. All rights reserved.
//

import UIKit

enum PhotoType {
    case positive
    case negative
}

class MainViewController: BaseViewController ,UIActionSheetDelegate, UIImagePickerControllerDelegate, UINavigationControllerDelegate, PECropViewControllerDelegate{
    
    @IBOutlet weak var positiveButton: UIButton!
    
    @IBOutlet weak var negativeButton: UIButton!
    
    var actionSheet:UIActionSheet?
    
    var photoType:PhotoType?
    
    var positiveImage:UIImage?
    var negativeImage:UIImage?
    
    override init(nibName nibNameOrNil: String?, bundle nibBundleOrNil: NSBundle?) {
        super.init(nibName: nibNameOrNil, bundle: nibBundleOrNil)
    }

    required init(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        
        self.positiveButton.layer.cornerRadius = 5
        self.positiveButton.layer.borderWidth = 0
        self.positiveButton.layer.borderColor = UIColor.clearColor().CGColor
        self.positiveButton.layer.masksToBounds = true
        
        self.negativeButton.layer.cornerRadius = 5
        self.negativeButton.layer.borderWidth = 0
        self.negativeButton.layer.borderColor = UIColor.clearColor().CGColor
        self.negativeButton.layer.masksToBounds = true
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func combine(sender: AnyObject) {
        if self.positiveImage == nil || self.negativeImage == nil {
            var alert:UIAlertView = UIAlertView(title: "", message: "请选择照片", delegate: self, cancelButtonTitle: "知道了")
            alert.show()
            return
        }
        var image:UIImage = combineImage(self.positiveImage!, withRect: CGRectMake(20, 40, 600, 380), image2: self.negativeImage!, withRect: CGRectMake(20, 480, 600, 380))
        
        var controller:CombineImageViewController = CombineImageViewController(nibName: "CombineImageViewController", bundle: nil)
        controller.image = image
        
        var navController:UINavigationController = UINavigationController(rootViewController: controller)
        self.presentViewController(navController, animated: true, completion: nil)
    }
    
    func combineImage(image1:UIImage, withRect rect1:CGRect, image2:UIImage, withRect rect2:CGRect)->UIImage {
        var size:CGSize = CGSizeMake(640, 900)
        UIGraphicsBeginImageContext(size)
        image1.drawInRect(rect1)
        image2.drawInRect(rect2)
        var resultImage:UIImage = UIGraphicsGetImageFromCurrentImageContext()
        UIGraphicsEndImageContext()
        return resultImage
    }
        

    @IBAction func takePositivePhoto(sender: AnyObject) {
        photoType = PhotoType.positive
        showActionSheet(photoType!)
    }
    
    
    @IBAction func takeNegativePhoto(sender: AnyObject) {
        photoType = PhotoType.negative
        showActionSheet(photoType!)
    }
    
    func showActionSheet(type:PhotoType) {
        var title:String = type == PhotoType.positive ? "选取身份证正面照片" : "选取身份证反面照片"
        self.actionSheet = UIActionSheet(title: title, delegate: self, cancelButtonTitle: "取消", destructiveButtonTitle: nil, otherButtonTitles: "拍照", "从相册选择")
        self.actionSheet?.showInView(self.view)
    }
    
    func actionSheet(actionSheet: UIActionSheet, clickedButtonAtIndex buttonIndex: Int) {
        if buttonIndex == actionSheet.cancelButtonIndex {
            return
        }
        if buttonIndex == 1 {
            if UIImagePickerController.isSourceTypeAvailable(UIImagePickerControllerSourceType.Camera) {
                var imagePickerController:UIImagePickerController = UIImagePickerController()
                imagePickerController.sourceType = UIImagePickerControllerSourceType.Camera
                imagePickerController.delegate = self
                self.presentViewController(imagePickerController, animated: true, completion: nil)
            }
        }
        else if buttonIndex == 2 {
            if UIImagePickerController.isSourceTypeAvailable(UIImagePickerControllerSourceType.PhotoLibrary) {
                var imagePickerController:UIImagePickerController = UIImagePickerController()
                imagePickerController.sourceType = UIImagePickerControllerSourceType.PhotoLibrary
                imagePickerController.delegate = self
                self.presentViewController(imagePickerController, animated: true, completion: nil)
            }
        }
    }
    
    func cropImage(picker:UIImagePickerController, image:UIImage) {
        var cropViewController:PECropViewController = PECropViewController();
        cropViewController.delegate = self
        cropViewController.keepingCropAspectRatio = true
        cropViewController.toolbarHidden = true
        cropViewController.rotationEnabled = true
        cropViewController.image = image
        cropViewController.imagePickerViewController = picker
        cropViewController.imageCropRect = CGRectMake(0, 0, 300, 190)
        cropViewController.cropRect = CGRectMake(0, 0, 300, 190)
        
        var navController:UINavigationController = UINavigationController(rootViewController: cropViewController)
        
        cropViewController.title = "裁剪照片"
        
        picker.presentViewController(navController, animated: true, completion: nil)
    }
        
    func imagePickerController(picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [NSObject : AnyObject]) {
        var image:UIImage = info[UIImagePickerControllerOriginalImage] as UIImage
        cropImage(picker, image: image);
    }
    
    func cropViewController(controller: PECropViewController!, didFinishCroppingImage croppedImage: UIImage!) {
        didChoosePhoto(croppedImage)
    }
    
    func didChoosePhoto(image:UIImage) {
        
        var originalImage:UIImage
        if max(image.size.width, image.size.height) > 600 * 2 {
            var widthRate:CGFloat = image.size.width/600
            var heightRate:CGFloat = image.size.height/600
            var sizeRate:CGFloat = max(widthRate, heightRate)
            var originalSize:CGSize = CGSizeMake(image.size.width/sizeRate, image.size.height/sizeRate)
            originalImage = image.resizedImage(originalSize, interpolationQuality: kCGInterpolationHigh)
        }
        else {
            originalImage = image
        }
        
        switch photoType!
        {
        case PhotoType.positive:
            self.positiveImage = originalImage
            self.positiveButton.setBackgroundImage(originalImage, forState: UIControlState.Normal)
            self.positiveButton.setTitle("", forState: UIControlState.Normal)
        case PhotoType.negative:
            self.negativeImage = originalImage
            self.negativeButton.setBackgroundImage(originalImage, forState: UIControlState.Normal)
            self.negativeButton.setTitle("", forState: UIControlState.Normal)
        }
    }

}
