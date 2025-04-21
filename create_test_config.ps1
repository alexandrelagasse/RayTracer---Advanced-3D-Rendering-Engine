$testContent = @"
# Fichier de test pour libconfig
scene = {
  camera: {
    resolution_width = 1920;
    resolution_height = 1080;
    position_x = 0.0;
    position_y = 0.0;
    position_z = 0.0;
    fieldOfView = 60.0;
  };
  
  primitives: {
    sphere = (
      {
        name = "TestSphere";
        position_x = 0.0;
        position_y = 0.0;
        position_z = 5.0;
        radius = 1.0;
        material = "TestMaterial";
      }
    );
  };
  
  materials: {
    SimpleMaterial = (
      {
        name = "TestMaterial";
        baseColor_r = 1.0;
        baseColor_g = 0.0;
        baseColor_b = 0.0;
      }
    );
  };
};
"@

$testContent | Out-File -FilePath "Scenes/test_scene.cfg" -Encoding utf8

Write-Host "Fichier de test créé: Scenes/test_scene.cfg" 