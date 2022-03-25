// SPDX-License-Identifier: LicenseRef-AGPL-3.0-only-OpenSSL

#ifndef CHIAKI_SETTINGSDIALOG_H
#define CHIAKI_SETTINGSDIALOG_H

#include <QDialog>
#include "mainwindow.h"

class Settings;
class QListWidget;
class QComboBox;
class QCheckBox;
class QLineEdit;

class SettingsDialog : public QDialog
{
	Q_OBJECT

	private:
		MainWindow *parentWindow;
		Settings *settings;

		QCheckBox *log_verbose_check_box;
		QComboBox *disconnect_action_combo_box;

		QComboBox *resolution_combo_box;
		QComboBox *fps_combo_box;
		QLineEdit *bitrate_edit;
		QComboBox *codec_combo_box;
		QLineEdit *audio_buffer_size_edit;
		QComboBox *audio_device_combo_box;
		QCheckBox *pi_decoder_check_box;
		QComboBox *hw_decoder_combo_box;

		QListWidget *registered_hosts_list_widget;
		QPushButton *delete_registered_host_button;

		void UpdateBitratePlaceholder();

	private slots:
		void LogVerboseChanged();
		void DisconnectActionSelected();

		void ResolutionSelected();
		void FPSSelected();
		void BitrateEdited();
		void CodecSelected();
		void AudioBufferSizeEdited();
		void AudioOutputSelected();
		void HardwareDecodeEngineSelected();
		void UpdateHardwareDecodeEngineComboBox();

		void UpdateRegisteredHosts();
		void UpdateRegisteredHostsButtons();
		void RegisterNewHost();
		void DeleteRegisteredHost();

	protected:
		void closeEvent(QCloseEvent *event);

	public:
		SettingsDialog(Settings *settings, MainWindow *parent = nullptr);
};

#endif // CHIAKI_SETTINGSDIALOG_H
