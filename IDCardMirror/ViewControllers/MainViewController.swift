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

class MainViewController: BaseViewController ,UIActionSheetDelegate, UIImagePickerControllerDelegate, UINavigationControllerDelegate{
    
    @IBOutlet weak var positiveButton: UIButton!
    
    @IBOutlet weak var negativeButton: UIButton!
    
    var actionSheet:UIActionSheet?
    
    var photoType:PhotoType?
    
    override init(nibName nibNameOrNil: String?, bundle nibBundleOrNil: NSBundle?) {
        super.init(nibName: nibNameOrNil, bundle: nibBundleOrNil)
    }

    required init(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
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
    
    func imagePickerController(picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [NSObject : AnyObject]) {
        var image:UIImage = info[UIImagePickerControllerOriginalImage] as UIImage
        switch photoType!
        {
        case PhotoType.positive:
            self.positiveButton.setBackgroundImage(image, forState: UIControlState.Normal)
        case PhotoType.negative:
            self.negativeButton.setBackgroundImage(image, forState: UIControlState.Normal)
        }
        self.dismissViewControllerAnimated(true, completion: nil)
    }

}
