### Kursinhalt embdded software 2026

### Allgemeines  
**Basic HW**  
   Esp32 board mit MPU6050  
**Ext HW**  
    Tumbler Robot
    
### User interface  
Die uC-Programme werden über das One-Button-Menü oder SvVis-Commands ( *SvProtocol* ) parametriert und gesteuert.  
Online-Werte werden über SvVis-Kanäle visualisiert.  
Ein SvVis konformes printf steht zur verfügung.  
SvVis3 wird als standart Oberfläche zum Betrieb der uC-Programme verwendet.  
Für manche Übungen werden eigene GUI's in Python oder C# erstellt.  
Die eigenen GUI's kommunizieren über *SvProtocol* mit dem uC

### Basics1
- uC Template-App zur Verwendung von *SvProtocol* und SvVis.  
  das HelloWorld für alle weiteren uC-Apps
- MPU-Daten ( Acc/Gyro ) vom Treiber lesen und im SvVis darstellen und analysieren.  
  TP-Filterung besprechen und demonstrieren.
- Eigene GUI mit *SvProtocol*. Verwendung des Templates SvVisMinni.cs oder SvVisMinni.py
- Projekt 2-Dim Wasserwaage.  
  Cursor in der GUI mit Acc-Sensor steuern  
  
### Led-Strip
Auf dem Tumbler-Board befindet sich ein LED-Strip ( 8-RGB Leds ),  
welche einzeln mit Farbe, Helligkeit, und Kontrast angesteuert werden können.  
Damit sind der Fantasie keine Grenzen mehr gesetzt.
**Matura Pool:**  
Anzeige der Acc-Wasserwage auf dem Led-Strip













