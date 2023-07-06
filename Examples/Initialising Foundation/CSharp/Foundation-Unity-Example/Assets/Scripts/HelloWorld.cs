// ------------------------------------------------------------------
// Copyright (c) Magnopus. All Rights Reserved.
// ------------------------------------------------------------------

using Csp;
using UnityEngine;

public class HelloWorld : MonoBehaviour
{

    private const string endPointUri = "https://ogs-ostage.magnoboard.com";
    private const string TenantKey = "FOUNDATION_HELLO_WORLD";
    // Initialisation of Foundation
    private void Awake()
    {
        var userAgent = new ClientUserAgent()
        {
            CHSEnvironment = "OStage",
            ClientEnvironment = "Stage",
            ClientOS = SystemInfo.operatingSystem,
            ClientSKU = "foundation-cSharp-examples",
            ClientVersion = "0.0.2",
            CSPVersion = CSPFoundation.GetBuildID()
        };

        if (CSPFoundation.Initialise(endPointUri, TenantKey))
        {
            Debug.Log("Successfully Initialised...");

        }
        else
        {
            Debug.Log("Failed to Initialise...");
        }

        if (CSPFoundation.GetIsInitialised())
        {
            if(CSPFoundation.Shutdown())
            {
                Debug.Log("Successfully Shutdown...");
            }else
            {
                Debug.Log("Failed to Shutdown...");
            }
            
        }
    }
}