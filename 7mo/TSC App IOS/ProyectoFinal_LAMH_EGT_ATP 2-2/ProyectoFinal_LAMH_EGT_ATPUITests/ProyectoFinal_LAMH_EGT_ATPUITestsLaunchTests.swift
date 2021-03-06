//
//  ProyectoFinal_LAMH_EGT_ATPUITestsLaunchTests.swift
//  ProyectoFinal_LAMH_EGT_ATPUITests
//
//  Created by user201238 on 11/16/21.
//

import XCTest

class ProyectoFinal_LAMH_EGT_ATPUITestsLaunchTests: XCTestCase {

    override class var runsForEachTargetApplicationUIConfiguration: Bool {
        true
    }

    override func setUpWithError() throws {
        continueAfterFailure = false
    }

    func testLaunch() throws {
        let app = XCUIApplication()
        app.launch()

        // Insert steps here to perform after app launch but before taking a screenshot,
        // such as logging into a test account or navigating somewhere in the app

        let attachment = XCTAttachment(screenshot: app.screenshot())
        attachment.name = "Launch Screen"
        attachment.lifetime = .keepAlways
        add(attachment)
    }
}
