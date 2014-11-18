//
//  CombineImageViewController.swift
//  IDCardMirror
//
//  Created by 胡瑨 on 14/11/18.
//  Copyright (c) 2014年 HJ. All rights reserved.
//

import UIKit
import AssetsLibrary

class CombineImageViewController: BaseViewController {
    
    @IBOutlet weak var imageView: UIImageView!
    
    var image:UIImage!
    
    override init(nibName nibNameOrNil: String?, bundle nibBundleOrNil: NSBundle?) {
        super.init(nibName: nibNameOrNil, bundle: nibBundleOrNil)
    }

    required init(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        self.title = "合体照"
        
        imageView.image = image
        
        self.navigationItem.leftBarButtonItem = UIBarButtonItem(title: "返回", style: UIBarButtonItemStyle.Plain, target: self, action: "cancel")
        self.navigationItem.rightBarButtonItem = UIBarButtonItem(title: "保存", style: UIBarButtonItemStyle.Done, target: self, action: "save")
    }
    
    func cancel() {
        self.dismissViewControllerAnimated(true, completion: nil)
    }
    
    func save () {
        UIImageWriteToSavedPhotosAlbum(self.image, nil, nil, nil)
        var alert:UIAlertView = UIAlertView(title: "", message: "保存成功，请到相册中查看", delegate: nil, cancelButtonTitle: "好的")
        alert.show()
        cancel()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

}
