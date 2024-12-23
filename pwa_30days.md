s

<br>
<!-----------------------------------------------------------------------  This is comment   --------------------------------------------------------------------->
<!---------------------------------------------------------------------------------------------------------------------------------------------------------------->

# [30 Days of PWA](https://microsoft.github.io/win-student-devs/#/30DaysOfPWA/README)

## 1. Core Concepts

### 1.1 [ <span style="font-weight: bold; color: green"> Introducing PWA ](https://microsoft.github.io/win-student-devs/#/30DaysOfPWA/core-concepts/01)  

- A Progressive Web App (PWA) is a traditional web app that is progressively enhanced using open web technologies, to make sure it delivers the best possible 
  experience on every device, based on available capabilities.

  1) <span style="font-weight: bold; color: #e1881c"> Platform-specific apps work only on their device platform.</span>  
      You need one codebase per platform and possibly a specialized developer team (familiar with tools, languages) - but you get to access to all platform capabilities.

  2) <span style="font-weight: bold; color: #0098ff"> Web apps work everywhere with a single codebase</span>   
      They can run across browsers, and all devices that browsers run on - using a single codebase. However, this limits them from using platform-specific capabilities that may not be supported everywhere.

- On older devices and browsers  
  where nothing new may be detected, it delivers a baseline website experience.

- On newer devices  
  it can detect device form factors and deliver responsive experiences that align with platform-specific behaviors.

- On modern browsers  
  it can detect support for Service Workers and Web App Manifest, and use those to unlock and support features like installability and offline operation - just like platform-specific apps.

- They have the reach of websites  
  They can be indexed by search engines, discovered or shared by URL, and used from any device with a browser.

- They can behave like platform-specific apps.  
  They can work offline, be installed on device, handle push notifications, and access rich device hardware.

- They can use rich platform capabilities  
  Ex: on Windows, PWA can be added to Start Menu, pinned to Taskbar, provide Share Targets for other apps & be published in Microsoft Store with other Windows apps.

- They can reduce costs  
  PWAs are developed for all platforms from one codebase - not only does this reduce maintainability costs, it requires a single development team vs. multiple platform-specific teams, to deliver the same experiences.

### 1.2  [ <span style="font-weight: bold; color: green"> Deconstructing PWA](https://microsoft.github.io/win-student-devs/#/30DaysOfPWA/core-concepts/02)

- Building Blocks of PWA 
  ```
    1. HTTPS                 - makes your PWA secure.
    2. Service Workers       - makes your PWA reliable and network-independent.
    3. Web App Manifest      - makes your PWA installable.
  ```

- Following Fields in the developer tools can be used for inspecting the PWA 
  ```
    1. Application           - with Manifest, Service Workers and Storage
    2. Storage               - options including Local Storage, Session Storage, Indexed DB
    3. Cache                 - representing Cache Storage in browser
    4. Background Services   - profiling panel to view/debug these activities.
  ```

- Audit your PWA using this site - https://www.pwabuilder.com/  
  
  <span style="color: #e1881c"> 1. HTTPS </span>  
  - 
  - HTTPS protocol is used for encrypting end-to-end communication between client and server of PWA by default.  
  - HTTPS is mandatory for Service Workers  
  - Publish your PWA to an HTTPS-enabled endpoint  
  - When using your own hosting provider, create the required certificates using free services like - " Let’s Encrypt "
  
  <span style="color: #e1881c"> 2. Service Workers </span>  
  - 
  - Service Workers are a special type of Web Worker, a JavaScript task that can run in the background (for asynchronous or long-running operations) without impacting the performance of the page
  - Service Workers make your PWA reliable and network-independent, ensuring that it provides a usable experience when device is offline. It achieves this by using following two services:  
  
      <span style=" color: green"> 1. Fetch API (Interception) </span>  
      Service Workers can intercept, modify and respond to all network requests from the application dynamically. They can listen for events indicating network changes, adapting their fetch responses based on the runtime conditions and app context.

      <span style=" color: green"> 2. Cache API (Storage) </span>  
      Service Workers can access client-side Cache as well as asynchronous storage options (like IndexedDB) to proactively store resources for offline access or performance efficiency.

  <span style="color: #e1881c"> 3. Web App Manifest </span>  
  - 
  - 'Web Application Manifest' makes the app installable like a platform-specific app. It’s a 'W3C' 
    Specification defining a JSON-based file format which provides developers with a centralized place to put metadata associated with apps.

  - It is a 2-step process:
  
    1. Create your manifest.json file and associate it with your PWA by referencing it in the head 
      of your  HTML page (see below).

    2. Populate the file with required properties (for minimal PWA) and other recommended or 
      optional properties (for a best-in class PWA experience).

        ```
          <link rel="manifest" href="/manifest.json">
        ```