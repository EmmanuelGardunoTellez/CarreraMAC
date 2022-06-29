//
//  ViewController.swift
//  ComunicacionDeSegues
//
//  Created by user201238 on 11/6/21.
//

import UIKit

class ViewController: UIViewController {
    
    
    @IBOutlet var interruptor: UISwitch!
    
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }
    
    
    @IBAction func BotonMorado(_ sender: Any) {
        
        if interruptor.isOn{
            performSegue(withIdentifier: "Morado", sender: nil)
        }
    }
    

    @IBAction func BotonNaranja(_ sender: Any) {
        
        if interruptor.isOn{
            performSegue(withIdentifier: "Naranja", sender: nil)
        }
    }
    
}

