$configFiles = Get-ChildItem -Path "Scenes" -Filter "*.cfg"

foreach ($file in $configFiles) {
    Write-Host "Traitement du fichier: $($file.Name)"
    
    # Lire le contenu du fichier
    $content = Get-Content -Path $file.FullName -Raw
    
    # Vérifier si le fichier commence par un nom de configuration suivi d'une accolade
    if ($content -match '^(camera|primitives|lights|materials|skybox)') {
        # Ajouter une section racine autour du contenu existant
        $newContent = "scene = {\n" + $content + "\n};"
        
        # Écrire les modifications
        $newContent | Set-Content -Path $file.FullName -Encoding UTF8
        Write-Host "Section racine ajoutée à: $($file.Name)"
    } else {
        Write-Host "Fichier déjà correct ou format non reconnu: $($file.Name)"
    }
}

Write-Host "Tous les fichiers ont été corrigés. Veuillez recompiler et tester." 