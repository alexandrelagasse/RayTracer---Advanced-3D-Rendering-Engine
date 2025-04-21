$configFiles = Get-ChildItem -Path "Scenes" -Filter "*.cfg"

foreach ($file in $configFiles) {
    Write-Host "Traitement du fichier: $($file.Name)"
    
    # Lire le contenu du fichier
    $content = Get-Content -Path $file.FullName -Raw
    
    # 1. Nettoyer les points-virgules multiples
    $content = $content -replace ';;+', ';'
    
    # 2. Corriger les syntaxes endommagées
    $content = $content -replace '\);PlanePlane', ');\n\nPlane'
    $content = $content -replace '\);PlaneMaterialPlaneMaterial', ');\n\nPlaneMaterial'
    
    # 3. Supprimer les points-virgules au début des lignes
    $content = $content -replace '(\n\s*);', '$1'
    
    # 4. Corriger les commentaires
    $content = $content -replace '#In degrees', '// In degrees'
    
    # 5. Supprimer l'espace après skybox
    $content = $content -replace 'skybox : \{', 'skybox: {'
    
    # 6. Ajouter une section racine au début du fichier
    $content = "scene = {\n" + $content + "\n};"
    
    # Écrire les modifications
    $content | Set-Content -Path $file.FullName -Encoding UTF8
    Write-Host "Fichier nettoyé et section racine ajoutée à: $($file.Name)"
}

Write-Host "Tous les fichiers ont été nettoyés et corrigés. Veuillez recompiler et tester." 