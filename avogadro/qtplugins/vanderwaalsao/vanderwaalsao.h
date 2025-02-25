/******************************************************************************

  This source file is part of the Avogadro project.

  Copyright 2012 Kitware, Inc.
  Copyright 2013 Tim Vandermeersch <tim.vandermeersch@gmail.com>

  This source code is released under the New BSD License, (the "License").

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

******************************************************************************/

#ifndef AVOGADRO_QTPLUGINS_VANDERWAALSAO_H
#define AVOGADRO_QTPLUGINS_VANDERWAALSAO_H

#include <avogadro/qtgui/sceneplugin.h>

namespace Avogadro {
namespace QtPlugins {

/**
 * @brief Render the molecule as Van der Waals spheres with ambient occlusion.
 * @author Tim Vandermeersch
 */
class VanDerWaalsAO : public QtGui::ScenePlugin
{
  Q_OBJECT

public:
  explicit VanDerWaalsAO(QObject* parent = nullptr);
  ~VanDerWaalsAO() override;

  void process(const QtGui::Molecule& molecule,
               Rendering::GroupNode& node) override;

  QString name() const override { return tr(m_name.c_str()); }

  QString description() const override
  {
    return tr("Simple display of VdW spheres with ambient occlusion.");
  }

  DefaultBehavior defaultBehavior() const override
  {
    return DefaultBehavior::False;
  }

private:
  std::string m_name = "Van der Waals (AO)";
};
} // namespace QtPlugins
} // namespace Avogadro

#endif // AVOGADRO_QTPLUGINS_VANDERWAALSAO_H
