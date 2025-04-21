$configFiles = Get-ChildItem -Path "Scenes" -Filter "*.cfg"

foreach ($file in $configFiles) {
    Write-Host "Traitement du fichier: $($file.FullName)"
    
    # Lire le contenu du fichier
    $content = Get-Content -Path $file.FullName -Raw
    
    # 1. Corriger la syntaxe skybox
    $content = $content -replace 'skybox : \{', 'skybox: {'
    
    # 2. Corriger SimpleSkybox parenthèse
    $content = $content -replace '\)\s+\};', ');};'
    $content = $content -replace '\)\s*$', ');'
    
    # 3. Corriger les commentaires
    $content = $content -replace '#In degrees', '// In degrees'
    
    # 4. Correction importante: ajouter un point-virgule après la parenthèse fermante dans les listes
    $content = $content -replace '\s+\)\s+;', ' );'
    $content = $content -replace '\s+\)\s+(\w)', ' );\n$1'
    
    # 5. S'assurer qu'il y a un point-virgule après SimpleMaterial et avant PlaneMaterial dans Toulouse.cfg
    $content = $content -replace '\)\s+PlaneMaterial', ');\n    PlaneMaterial'
    
    # 6. Pour Toulouse.cfg - corriger la syntaxe des sphères
    $content = $content -replace '\),\s+sphere', ');\n\tsphere'
    
    # 7. S'assurer que chaque primitive se termine par );\n
    $content = $content -replace '(\s+)\);(\s*)\n(\s*)\};', '$1);\n$3};'
    
    # 8. S'assurer que chaque bloc de configuration se termine par };
    $content = $content -replace '\}(\s*\n\s*[a-zA-Z])', '};\n$1'
    
    # 9. Corriger l'erreur spécifique dans Toulouse.cfg
    if ($file.Name -eq "Toulouse.cfg" -or $file.Name -eq "Toulouse_02.cfg") {
        $content = $content -replace '\);(\s*\n\s*)SimpleSkybox', ');$1SimpleSkybox'
    }
    
    # Écrire les modifications
    $content | Set-Content -Path $file.FullName -Encoding UTF8
    Write-Host "Fichier corrigé: $($file.Name)"
}

Write-Host "Tous les fichiers ont été corrigés. Veuillez recompiler et tester." 