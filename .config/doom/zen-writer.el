;;; zen-writer.el -*- lexical-binding: t; -*-

(defun y/zen ()
  (interactive)
  (setq doom-theme 'doom-zen-writer)
  (load-theme doom-theme t)
  (hl-sentence-mode +1))

(defun y/unzen ()
  (interactive)
  (y/auto-update-theme)
  (hl-sentence-mode -1))

(defun y/zen-full ()
  (interactive)
  (y/zen)
  (toggle-frame-fullscreen)
  (doom-big-font-mode +1))

(defun y/unzen-full ()
  (interactive)
  (y/unzen)
  (toggle-frame-fullscreen)
  (doom-big-font-mode -1))

(map! :leader
      (:prefix ("y z" . "Zen Writer")
       :desc "Full Zen Writer" "z" #'y/zen-full
       :desc "un-Full Zen Writer" "u" #'y/unzen-full
       :desc "Zen Writer" "t" #'y/zen
       :desc "un-Zen Writer" "q" #'y/unzen))
